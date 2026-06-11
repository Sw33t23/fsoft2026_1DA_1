#ifndef GALO_VIEW_H
#define GALO_VIEW_H

#include <string>
#include <utility>

class GaloView {
public:
    char pedirSimboloJogador();
    std::pair<int, int> pedirJogada();
    void mostrarTabuleiro(const char tabuleiro[4][4]);
    void mostrarMensagem(const std::string& mensagem);
    void mostrarResultado(char resultado, int vitorias);
};

#endif