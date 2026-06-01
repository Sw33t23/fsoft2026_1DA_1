#ifndef UNTITLED1_RANKING_H
#define UNTITLED1_RANKING_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct EntradaRanking {
    string username;
    int valor;
};

class Ranking {
public:
    void atualizarBlackjack  (string username, int saldo);
    void atualizarGalo       (string username, int vitorias_consecutivas);
    void atualizarMaiorMenor (string username, int tentativas);

    void consultarRanking();

private:
    std::vector<EntradaRanking> rankingBlackjack;
    std::vector<EntradaRanking> rankingGalo;
    std::vector<EntradaRanking> rankingMaiorMenor;

    void exibirTop10(std::vector<EntradaRanking> lista, string nomeJogo, string colunaValor);
};

#endif //UNTITLED1_RANKING_H
