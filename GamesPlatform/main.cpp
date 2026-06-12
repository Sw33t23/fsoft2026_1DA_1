#include <iostream>
#include "Headers/Container/JogadorContainer.h"
#include "Headers/Service/JogadorService.h"
#include "Headers/Controller/JogadorController.h"
#include "Headers/Controller/MenuController.h"
#include "Headers/Controller/RankingController.h"
#include "Headers/Model/Jogador.h"

int main() {
    JogadorContainer jogadorContainer;
    JogadorService jogadorService(jogadorContainer);
    JogadorController jogadorController(jogadorService);
    RankingController rankingController;

    while (true) {
        Jogador* jogadorAtivo = jogadorController.correrMenuAutenticacao();

        if (jogadorAtivo == nullptr) {
            std::cout << "A fechar a aplicacao...\n";
            break;
        }

        MenuController menu(jogadorAtivo, rankingController);
        menu.iniciarMenu();
    }
    return 0;
}
