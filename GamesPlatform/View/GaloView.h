#ifndef GALOVIEW_H
#define GALOVIEW_H

#include <array>
#include <string>

// ============================================================
//  GaloView.h  –  Camada de apresentação do Jogo do Galo
//
//  Responsável por TUDO o que é mostrado ao utilizador:
//  menus, tabuleiro, instruções e resultados.
//  Não contém lógica de jogo.
// ============================================================

class GaloView {
public:

    // Mensagem 1 – pergunta se o jogador quer jogar
    // Devolve true se o jogador escolher jogar
    bool menuPrincipal(const std::string& nomeJogador);

    // Mensagem 2 – mostra as instruções e o mapa de posições
    void mostrarInstrucoes();

    // Mensagem 3 – pede ao jogador uma posição (1-9)
    // Devolve o número introduzido (sem validar se está livre – isso é do Controller)
    int pedirPosicao();

    // Mensagem 5 – mostra o tabuleiro atual
    // Recebe array de 9 chars (' ', 'X' ou 'O')
    void mostrarTabuleiro(const std::array<char, 9>& tabuleiro);

    // Feedback após jogada (mensagem 4 – "feedback posição")
    void mostrarFeedbackJogada(int posicao, bool valida);

    // Aviso de que o computador está a jogar (mensagem 6)
    void mostrarJogadaComputador();

    // Mensagem 8 – mostra o resultado final da partida
    // resultado: 'J' = jogador ganhou, 'C' = computador ganhou, 'E' = empate
    void mostrarResultadoFinal(char resultado, const std::string& nomeJogador);

    // Pergunta se o jogador quer jogar de novo
    bool perguntarJogarDeNovo();

    // Mostra as vitórias registadas na sessão
    void mostrarVitorias(const std::string& nomeJogador, int vitorias);
};

#endif // GALOVIEW_H