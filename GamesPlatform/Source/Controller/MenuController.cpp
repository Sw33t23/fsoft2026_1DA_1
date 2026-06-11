#include "../../Headers/Controller/MenuController.h"
#include "../../Headers/Controller/BlackjackController.h"
#include "../../Headers/Controller/GaloController.h"
#include "../../Headers/Controller/MaiorOuMenorController.h"
#include "../../Headers/Controller/RankingController.h"
#include <iostream>

MenuController::MenuController(Jogador* jogador) : jogadorAtivo(jogador) {}

void MenuController::mostrarMenu() const {
    std::cout << "\n====================================\n";
    std::cout << "             HUB DE JOGOS           \n";
    std::cout << "====================================\n";
    std::cout << "Utilizador: " << jogadorAtivo->username << "\n";
    std::cout << "------------------------------------\n";
    std::cout << "1. Jogar Blackjack\n";
    std::cout << "2. Jogar Jogo do Galo\n";
    std::cout << "3. Jogar Maior ou Menor\n";
    std::cout << "4. Ranking\n";
    std::cout << "0. Fazer Logout\n";
    std::cout << "------------------------------------\n";
    std::cout << "Escolha uma opcao: ";
}

void MenuController::iniciarMenu() {
    int opcao = -1;
    while (opcao != 0) {
        mostrarMenu();
        std::cin >> opcao;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000,'\n');

            std::cout << "\nOpcao invalida! Tente novamente.\n";
            opcao = -1;
            continue;
        }
        executarOpcao(opcao);
    }
}

void MenuController::executarOpcao(int opcao) {
    switch (opcao) {
        case 1: {
            BlackjackController blackjack(jogadorAtivo->username, jogadorAtivo->saldo);
            blackjack.playBlackjackRound(jogadorAtivo->saldo, ranking.getModel());
            break;
        }
        case 2: {
            GaloController galo(jogadorAtivo, &ranking.getModel());
            galo.iniciarJogo();
            break;
        }
        case 3: {
            MaiorOuMenorController maiorMenor(jogadorAtivo, &ranking.getModel());
            maiorMenor.playGame();
            break;
        }
        case 4: {
            ranking.consultarRanking();
            break;
        }
        case 0:
            std::cout << "\nSessao terminada. Ate a proxima, " << jogadorAtivo->username << "!\n";
            break;
        default:
            std::cout << "\nOpcao invalida! Tente novamente.\n";
            break;
    }
}