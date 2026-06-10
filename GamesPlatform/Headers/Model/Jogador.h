//
// Created by andre on 01/06/2026.
//

#ifndef JOGADOR_H
#define JOGADOR_H
#include <string>

using namespace std;

struct Jogador
{
    string username;
    string password;
    double saldo = 1000.0;
    int leastTrys = 10000;

    Jogador(string u, string p) : username(u), password(p) {}

    Jogador() = default;

    void setLeastTrys(int tentativas)
    {
        if (tentativas < leastTrys)
        {
            leastTrys = tentativas;
        }
    }
};


#endif //JOGADOR_H