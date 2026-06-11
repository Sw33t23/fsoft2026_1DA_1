#ifndef GALO_H
#define GALO_H

#include <vector>

class Galo {
private:
    char tabuleiro[3][3];
    char simboloJogador;
    char simboloIA;
    int vitorias;

    bool verificarVencedor(char simbolo) const;
    bool tabuleiroCheio() const;

public:
    Galo(char simJogador);
    
    bool validarEJogar(int linha, int coluna);
    void jogarComputador();
    char verificarResultado() const; // 'J' (Jogador), 'I' (IA), 'E' (Empate), ' ' (Ativo)
    bool jogoAtivo() const;
    
    void incrementarVitorias();
    int getVitorias() const;
    const char (*getTabuleiro() const)[3];
    char getSimboloJogador() const;
    char getSimboloIA() const;
};

#endif