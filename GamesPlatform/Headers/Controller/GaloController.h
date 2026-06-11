#ifndef GALO_CONTROLLER_H
#define GALO_CONTROLLER_H

#include "../Model/Galo.h"
#include "../Model/Ranking.h"
#include "../Model/Jogador.h"
#include "../View/GaloView.h"

class GaloController {
private:
    Galo* model;
    GaloView view;
    Jogador* jogadorAtivo;
    Ranking* ranking;

public:
    GaloController(Jogador* jogador, Ranking* ranking);
    ~GaloController();
    void iniciarJogo();
};

#endif