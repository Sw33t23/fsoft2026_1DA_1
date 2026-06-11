#include "../../Headers/Controller/MenuController.h"
#include "../../Headers/Controller/BlackjackController.h"
#include "../../Headers/Controller/GaloController.h"
#include "../../Headers/Controller/MaiorOuMenorController.h"
#include <iostream>

#include "Controller/RankingController.h"

MenuController::MenuController(Jogador* jogador) : jogadorAtivo(jogador) {}

void MenuController::mostrarMenu() const {
    std::cout << "\n====================================\n";
    std::cout << "               HUB DE JOGOS           \n";
    std::cout << "====================================\n";
    std::cout << "Utilizador: " << jogadorAtivo->username << "\n";
    std::cout << "Saldo Atual: " << jogadorAtivo->saldo << " EUR\n";
    std::cout << "------------------------------------\n";
    std::cout << "1. Jogar Blackjack\n";
    std::cout << "2. Jogar Jogo do Galo\n";
    std::cout << "3. Jogar Maior ou Menor\n";
    std::cout << "4. Ranking\n";
    std::cout << "0. Fazer Logout e Sair\n";
    std::cout << "------------------------------------\n";
    std::cout << "Escolha uma opcao: ";
}

void MenuController::iniciarMenu() {
    int opcao = -1;
    while (opcao != 0) {
        mostrarMenu();
        std::cin >> opcao;
        executarOpcao(opcao);
    }
}

void MenuController::executarOpcao(int opcao) {
    switch (opcao) {
        case 1: {
            std::cout << "\n[A abrir o Blackjack...]\n";
            BlackjackController blackjack(jogadorAtivo->username, jogadorAtivo->saldo);
            blackjack.playBlackjackRound(jogadorAtivo->saldo, ranking);
            break;
        }
        case 2: {
            std::cout << "\n[A abrir o Jogo do Galo...]\n";
            GaloController galo;
            galo.iniciarJogo();
            break;
        }
        case 3: {
            std::cout << "\n[A abrir o Maior ou Menor...]\n";
            MaiorOuMenorController maiorMenor(jogadorAtivo, &ranking);
            maiorMenor.playGame();
            break;
        }
        case 4: {
             // falta colocar o ranking

        }
        case 0:
            std::cout << "\nSessao terminada. Ate a proxima, " << jogadorAtivo->username << "!\n";
            break;
        default:
            std::cout << "\nOpcao invalida! Tente novamente.\n";
            break;
    }
}