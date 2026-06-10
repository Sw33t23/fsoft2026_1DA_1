#ifndef RANKING_MODEL_H
#define RANKING_MODEL_H
 
#include <string>
#include <vector>
#include <iostream>

using namespace std;
 
struct EntradaRanking {
    std::string username;
    int valor;
};
 
class Ranking {
public:
    void atualizarBlackjack (std::string username, int saldo);
    void atualizarGalo (std::string username, int vitorias_consecutivas);
    void atualizarMaiorMenor (std::string username, int tentativas);
 
    const std::vector<EntradaRanking>& getBlackjack() const { return rankingBlackjack; }
    const std::vector<EntradaRanking>& getGalo() const { return rankingGalo; }
    const std::vector<EntradaRanking>& getMaiorMenor() const { return rankingMaiorMenor; }
 
private:
    std::vector<EntradaRanking> rankingBlackjack;
    std::vector<EntradaRanking> rankingGalo;
    std::vector<EntradaRanking> rankingMaiorMenor;
}; 
#endif
