//
// Created by andre on 30/05/2026.
//

#ifndef FSOFT2026_1DA_1_CONTROLLER_H
#define FSOFT2026_1DA_1_CONTROLLER_H

#include "../Model/MaiorOuMenor.h"
#include "../Model/RankingModel.h"
#include "../Model/Jogador.h"

using namespace std;


class MaiorOuMenorController
{
private:
    MaiorOuMenor game;
    Jogador *loggedClient;
    RankingModel *ranking;

public:
    MaiorOuMenorController(Jogador *jogadorAutenticado, RankingModel *ranking);
    void playGame();
};

#endif //FSOFT2026_1DA_1_CONTROLLER_H