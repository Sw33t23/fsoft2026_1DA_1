//
// Created by andre on 01/06/2026.
//

#ifndef FSOFT2026_1DA_1_JOGADOR_H
#define FSOFT2026_1DA_1_JOGADOR_H
#include <string>

using namespace std;

struct Jogador
{
    string username;
    string password;
    double saldo = 1000.0;
    int leastTrys = 10000;

    void setLeastTrys(int tentativas)
    {
        if (tentativas < leastTrys)
        {
            leastTrys = tentativas;
        }
    }
};


#endif //FSOFT2026_1DA_1_JOGADOR_H