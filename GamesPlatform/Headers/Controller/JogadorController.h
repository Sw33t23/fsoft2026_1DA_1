#ifndef JOGADOR_CONTROLLER_H
#define JOGADOR_CONTROLLER_H

#include "../View/JogadorView.h"
#include "../Service/JogadorService.h"
#include "../Model/Jogador.h"

class JogadorController {
private:
    JogadorView view;
    JogadorService service;

public:
    JogadorController(JogadorService& service);

    Jogador* correrMenuAutenticacao();

private:
    void fluxoRegisto();
    Jogador* fluxoLogin();
};
#endif