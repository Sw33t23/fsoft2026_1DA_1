#include "../../Headers/Model/Ranking.h"
 
const int TOP_MAX = 10;
 
void Ranking::atualizarBlackjack(std::string username, int saldo) {
 
    for (int i = 0; i < (int)rankingBlackjack.size(); i++) {
        if (rankingBlackjack[i].username == username) {
            if (saldo > rankingBlackjack[i].valor) {
                rankingBlackjack[i].valor = saldo;
            }
            return;
        }
    }

    EntradaRanking novo;
    novo.username = username;
    novo.valor = saldo;
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
 
void Ranking::atualizarGalo(std::string username, int vitorias_consecutivas) {
 
    for (int i = 0; i < (int)rankingGalo.size(); i++) {
        if (rankingGalo[i].username == username) {
            if (vitorias_consecutivas > rankingGalo[i].valor) {
                rankingGalo[i].valor = vitorias_consecutivas;
            }
            return;
        }
    }
 
    EntradaRanking nova;
    nova.username = username;
    nova.valor = vitorias_consecutivas;
    rankingGalo.push_back(nova);
 
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
 
void Ranking::atualizarMaiorMenor(std::string username, int tentativas) {
 
    for (int i = 0; i < (int)rankingMaiorMenor.size(); i++) {
        if (rankingMaiorMenor[i].username == username) {
            if (tentativas < rankingMaiorMenor[i].valor) {
                rankingMaiorMenor[i].valor = tentativas;
            }
            return;
        }
    }
 
    EntradaRanking nova;
    nova.username = username;
    nova.valor = tentativas;
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
