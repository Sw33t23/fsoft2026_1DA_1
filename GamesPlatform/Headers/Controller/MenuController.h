#ifndef MENU_CONTROLLER_H
#define MENU_CONTROLLER_H

#include "../Model/Jogador.h"
#include "../Model/Ranking.h"

class MenuController {
private:
    Jogador* jogadorAtivo;
    Ranking ranking;

    void mostrarMenu() const;
    void executarOpcao(int opcao);

public:
    MenuController(Jogador* jogador);
    void iniciarMenu();
};

#endif