#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "../Model/Jogador.h"
#include "../Controller/RankingController.h"

class MenuController {
private:
    Jogador* jogadorAtivo;
    RankingController& ranking;

    void mostrarMenu() const;
    void executarOpcao(int opcao);

public:
    MenuController(Jogador* jogador, RankingController& ranking);
    void iniciarMenu();
};

#endif