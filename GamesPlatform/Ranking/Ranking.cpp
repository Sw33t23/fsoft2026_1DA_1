#include <iostream>

#include "Ranking.h"

const int TOP_MAX = 10;

void Ranking::atualizarBlackjack(string username, int saldo) {

    for (int i = 0; i < (int)rankingBlackjack.size(); i++) {
        if (rankingBlackjack[i].username == username) {
            if (saldo > rankingBlackjack[i].valor) {
                rankingBlackjack[i].valor = saldo;
            }
            return;
        }
    }

	// Jogador novo
    EntradaRanking novo;
    novo.username = username;
    novo.valor    = saldo;
    rankingBlackjack.push_back(novo);

    for (int i = 0; i < (int)rankingBlackjack.size() - 1; i++) {
        for (int j = 0; j < (int)rankingBlackjack.size() - 1 - i; j++) {
            if (rankingBlackjack[j].valor < rankingBlackjack[j+1].valor) {
                EntradaRanking temp  = rankingBlackjack[j];
                rankingBlackjack[j]  = rankingBlackjack[j+1];
                rankingBlackjack[j+1]= temp;
            }
        }
    }

    if ((int)rankingBlackjack.size() > TOP_MAX) {
        rankingBlackjack.pop_back();
    }
}

// GALO - vitorias conssecutivas

void Ranking::atualizarGalo(std::string username, int vitorias_consecutivas) {

    for (int i = 0; i < (int)rankingGalo.size(); i++) {
        if (rankingGalo[i].username == username) {
            if (vitorias_consecutivas > rankingGalo[i].valor) {
                rankingGalo[i].valor = vitorias_consecutivas;
            }
            return;
        }
    }

    // Jogador novo
    EntradaRanking nova;
    nova.username = username;
    nova.valor    = vitorias_consecutivas;
    rankingGalo.push_back(nova);

    // Ordena do maior para o menor numero de vitorias consecutivas
    for (int i = 0; i < (int)rankingGalo.size() - 1; i++) {
        for (int j = 0; j < (int)rankingGalo.size() - 1 - i; j++) {
            if (rankingGalo[j].valor < rankingGalo[j+1].valor) {
                EntradaRanking temp = rankingGalo[j];
                rankingGalo[j]      = rankingGalo[j+1];
                rankingGalo[j+1]    = temp;
            }
        }
    }

    if ((int)rankingGalo.size() > TOP_MAX) {
        rankingGalo.pop_back();
    }
}

// MAIOR OU MENOR — guarda o menor nº de tentativas para acertar

void Ranking::atualizarMaiorMenor(std::string username, int tentativas) {

    for (int i = 0; i < (int)rankingMaiorMenor.size(); i++) {
        if (rankingMaiorMenor[i].username == username) {
            if (tentativas < rankingMaiorMenor[i].valor) {
                rankingMaiorMenor[i].valor = tentativas;
            }
            return;
        }
    }

    // Jogador novo
    EntradaRanking nova;
    nova.username = username;
    nova.valor    = tentativas;
    rankingMaiorMenor.push_back(nova);

    for (int i = 0; i < (int)rankingMaiorMenor.size() - 1; i++) {
        for (int j = 0; j < (int)rankingMaiorMenor.size() - 1 - i; j++) {
            if (rankingMaiorMenor[j].valor > rankingMaiorMenor[j+1].valor) {
                EntradaRanking temp   = rankingMaiorMenor[j];
                rankingMaiorMenor[j]  = rankingMaiorMenor[j+1];
                rankingMaiorMenor[j+1]= temp;
            }
        }
    }

    if ((int)rankingMaiorMenor.size() > TOP_MAX) {
        rankingMaiorMenor.pop_back();
    }
}



// Mostrar o top 10

void Ranking::exibirTop10(std::vector<EntradaRanking> lista, string titulo, string colunaValor) {
    std::cout << "\n=== TOP 10 - " << titulo << " ===\n";

    if (lista.empty()) {
        std::cout << "Sem registos ainda.\n";
    } else {
        for (int i = 0; i < (int)lista.size(); i++) {
            std::cout << (i + 1) << ". " << lista[i].username << " - " << colunaValor << ": " << lista[i].valor << "\n";
        }
    }
    std::cout << "\n";
}

// Menu de ranking

void Ranking::consultarRanking() {
    int opcao = -1;

    while (opcao != 0) {
        std::cout << "\n--- RANKING ---\n"
                  << "1. Blackjack\n"
                  << "2. Galo\n"
                  << "3. Maior ou Menor\n"
                  << "0. Voltar\n"
                  << "Opcao: ";
        std::cin >> opcao;

        if (opcao == 1) {
            exibirTop10(rankingBlackjack,  "Blackjack",      "Saldo");
        } else if (opcao == 2) {
            exibirTop10(rankingGalo,        "Galo",           "Streak");
        } else if (opcao == 3) {
            exibirTop10(rankingMaiorMenor,  "Maior ou Menor", "Tentativas");
        } else if (opcao == 0) {
            std::cout << "A voltar ao menu principal...\n";
        } else {
            std::cout << "Opcao invalida.\n";
        }
    }
}
