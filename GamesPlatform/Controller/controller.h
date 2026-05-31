//
// Created by andre on 30/05/2026.
//

#ifndef FSOFT2026_1DA_1_CONTROLLER_H
#define FSOFT2026_1DA_1_CONTROLLER_H

#include "MaiorOuMenor.h"
#include "../Ranking/Ranking.h"

using namespace std;


struct Client
{
    string username;
    int leastTrys = 10000;

    void setLeastTrys(int tentativas)
    {
        if (tentativas < leastTrys)
        {
            leastTrys = tentativas;
        }
    }
};

class MaiorOuMenorController
{
private:
    MaiorOuMenor game;
    Client *loggedClient;
public:
    MaiorOuMenorController(Client *loggedClient);
    void playGame();
};

#endif //FSOFT2026_1DA_1_CONTROLLER_H