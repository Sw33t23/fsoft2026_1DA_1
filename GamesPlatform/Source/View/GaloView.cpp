#include "../../Headers/View/GaloView.h"
#include <iostream>

char GaloView::pedirSimboloJogador() {
    char simbolo = ' ';
    while (simbolo != 'X' && simbolo != 'O') {
        std::cout << "Escolha o seu simbolo (X ou O): ";
        std::cin >> simbolo;
        simbolo = std::toupper(simbolo);
    }
    return simbolo;
}

std::pair<int, int> GaloView::pedirJogada() {
    int linha, coluna;
    std::cout << "Introduza a linha (1-3) e coluna (1-3) separadas por espaco: ";
    std::cin >> linha >> coluna;
    return {linha - 1, coluna - 1}; // Converte para índice 0-2
}

void GaloView::mostrarTabuleiro(const char tabuleiro[3][3]) {
    std::cout << "\n-------------\n";
    for (int i = 0; i < 3; i++) {
        std::cout << "| ";
        for (int j = 0; j < 3; j++) {
            std::cout << tabuleiro[i][j] << " | ";
        }
        std::cout << "\n-------------\n";
    }
}

void GaloView::mostrarMensagem(const std::string& mensagem) {
    std::cout << mensagem << std::endl;
}

void GaloView::mostrarResultado(char resultado, int vitorias) {
    if (resultado == 'J') {
        std::cout << "\n*** Parabens! Voce venceu! ***\n";
    } else if (resultado == 'I') {
        std::cout << "\n--- O computador venceu! ---\n";
    } else if (resultado == 'E') {
        std::cout << "\n... Foi um empate! ...\n";
    }
    std::cout << "Total de vitorias do jogador: " << vitorias << "\n\n";
}