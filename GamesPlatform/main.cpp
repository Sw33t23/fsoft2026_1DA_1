#include <iostream>
#include "Headers/Container/JogadorContainer.h"
#include "Headers/Service/JogadorService.h"
#include "Headers/Controller/JogadorController.h"
#include "Headers/Model/Jogador.h"
#include "Headers/Controller/MenuController.h" 

int main() {
    JogadorContainer jogadorContainer;
    JogadorService jogadorService(jogadorContainer);
    JogadorController jogadorController(jogadorService);

    Jogador* jogadorAtivo = jogadorController.correrMenuAutenticacao();

    if (jogadorAtivo == nullptr) {
        std::cout << "A fechar a aplicacao...\n";
        return 0;
    }

    MenuController menu(jogadorAtivo);
    menu.iniciarMenu();

    return 0;
}
