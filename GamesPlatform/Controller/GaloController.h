#ifndef GALOCONTROLLER_H
#define GALOCONTROLLER_H

#include "GaloView.h"
#include <array>
#include <string>

// ============================================================
//  GaloController.h  –  Controlador do Jogo do Galo
//
//  Orquestra toda a lógica do jogo seguindo o diagrama UC5:
//   - Valida jogadas
//   - Controla o loop principal
//   - Chama a View para apresentar resultados
//   - Gere a IA do computador
// ============================================================

class GaloController {
public:

    // Construtor – recebe a view por referência
    explicit GaloController(GaloView& view);

    // Ponto de entrada chamado pelo main principal (mensagem 1)
    // nomeJogador = loggedClient
    void iniciar(const std::string& nomeJogador);

private:

    GaloView& view_;                    // referência à camada de apresentação
    std::array<char, 9> tabuleiro_;     // estado do tabuleiro (0-8)
    int vitorias_;                      // vitórias da sessão (setWins)

    static const char JOGADOR    = 'X';
    static const char COMPUTADOR = 'O';

    // ---- Métodos internos ----

    // Inicializa todas as casas com ' '
    void inicializarTabuleiro();

    // Mensagem 4 – valida se a posição (1-9) é válida e livre
    // Devolve true e preenche idxOut (0-8) se for válida
    bool validarEJogar(int posicaoInput, int& idxOut);

    // Mensagem 6 – lógica da IA (ganhar > bloquear > aleatório)
    void jogarIA();

    // Mensagem 7 – verifica o resultado atual do tabuleiro
    // Devolve: 'J' jogador ganhou, 'C' computador ganhou,
    //          'E' empate, ' ' jogo continua
    char verificarResultado();

    // Mensagem 9 – atualiza vitórias do loggedClient
    void setWins(int vitorias);
};

#endif // GALOCONTROLLER_H