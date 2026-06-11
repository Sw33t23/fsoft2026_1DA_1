#ifndef RANKING_CONTROLLER_H
#define RANKING_CONTROLLER_H
 
#include <string>
#include "../Model/Ranking.h"
#include "../View/RankingView.h"
 
class RankingController {
public:
    void registarBlackjack (const std::string& username, int saldo);
    void registarGalo (const std::string& username, int vitorias_consecutivas);
    void registarMaiorMenor (const std::string& username, int tentativas);
 
    void consultarRanking();

    Ranking& getModel() { return model; }
 
private:
    Ranking model;
    RankingView  view;
};
#endif
