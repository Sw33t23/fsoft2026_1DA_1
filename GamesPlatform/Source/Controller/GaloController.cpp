// ============================================================
//  GaloController.cpp  –  Lógica do Jogo do Galo
//
//  Segue o diagrama de sequência UC5 passo a passo.
//  Cada bloco de código tem o número da mensagem correspondente.
// ============================================================

#include "../../Headers/Controller/GaloController.h"
#include <iostream>
#include <cstdlib>   // rand
#include <ctime>     // time

// ------------------------------------------------------------
//  Construtor
// ------------------------------------------------------------
GaloController::GaloController(GaloView& view)
    : view_(view), vitorias_(0) {
    inicializarTabuleiro();
    // Inicializar gerador de números aleatórios (uma vez)
    srand(static_cast<unsigned int>(time(nullptr)));
}

// ------------------------------------------------------------
//  iniciar – ponto de entrada chamado pelo main principal
//  Corresponde ao fluxo completo do diagrama UC5
// ------------------------------------------------------------
void GaloController::iniciar(const std::string& nomeJogador) {

    // --- Mensagem 1: menuPrincipal() ---
    if (!view_.menuPrincipal(nomeJogador)) {
        std::cout << "  Ate a proxima, " << nomeJogador << "!\n";
        return;
    }

    bool jogarDeNovo = true;

    while (jogarDeNovo) {

        // --- Mensagem 2: mostrarInstrucoes ---
        view_.mostrarInstrucoes();

        // Preparar tabuleiro novo para cada partida
        inicializarTabuleiro();
        char resultado = ' ';

        // =====================================================
        //  LOOP: [Enquanto não houver vencedor e houver casas vazias]
        // =====================================================
        while (resultado == ' ') {

            // --- Mensagem 5: mostrarTabuleiro (estado atual) ---
            view_.mostrarTabuleiro(tabuleiro_);

            // --- Mensagem 3: pedirPosicao() + getInt(label) via Utils ---
            int posicaoInput = view_.pedirPosicao();

            // --- Mensagem 4: validarEJogar(posicao) ---
            int idx = -1;
            bool valida = validarEJogar(posicaoInput, idx);

            // Feedback da jogada para o utilizador
            view_.mostrarFeedbackJogada(posicaoInput, valida);

            // Se a posição for inválida, volta a pedir sem avançar
            if (!valida) continue;

            // --- Mensagem 5: mostrarTabuleiro (após jogada humana) ---
            view_.mostrarTabuleiro(tabuleiro_);

            // --- Mensagem 7: verificarResultado() após jogada humana ---
            resultado = verificarResultado();
            if (resultado != ' ') break;  // jogo terminou

            // --- Mensagem 6: JogarIA(tabuleiro) ---
            view_.mostrarJogadaComputador();
            jogarIA();

            // --- Mensagem 5: mostrarTabuleiro (após jogada da IA) ---
            view_.mostrarTabuleiro(tabuleiro_);

            // --- Mensagem 7: verificarResultado() após jogada da IA ---
            resultado = verificarResultado();

        }
        // =====================================================
        //  FIM DO LOOP
        // =====================================================

        // --- Mensagem 8: mostrarResultadoFinal(resultado) ---
        view_.mostrarResultadoFinal(resultado, nomeJogador);

        // --- Mensagem 9: setWins(vitorias) → loggedClient ---
        if (resultado == 'J') {
            ++vitorias_;
            setWins(vitorias_);
        }

        // Perguntar se quer jogar de novo
        jogarDeNovo = view_.perguntarJogarDeNovo();
    }

    // Mostrar resumo da sessão
    view_.mostrarVitorias(nomeJogador, vitorias_);
}

// ------------------------------------------------------------
//  inicializarTabuleiro – preenche todas as casas com ' '
// ------------------------------------------------------------
void GaloController::inicializarTabuleiro() {
    tabuleiro_.fill(' ');
}

// ------------------------------------------------------------
//  Mensagem 4 – validarEJogar
//  Valida se a posição é entre 1-9 e se a casa está livre.
//  Se válida, coloca 'X' no tabuleiro e devolve true.
// ------------------------------------------------------------
bool GaloController::validarEJogar(int posicaoInput, int& idxOut) {
    // Verificar intervalo 1-9
    if (posicaoInput < 1 || posicaoInput > 9) {
        return false;
    }

    int idx = posicaoInput - 1;  // converter para índice 0-8

    // Verificar se a casa está livre
    if (tabuleiro_[idx] != ' ') {
        return false;
    }

    // Jogada válida – colocar símbolo do jogador
    tabuleiro_[idx] = JOGADOR;
    idxOut = idx;
    return true;
}

// ------------------------------------------------------------
//  Mensagem 6 – jogarIA
//  Estratégia: 1) ganhar  2) bloquear  3) aleatório
// ------------------------------------------------------------
void GaloController::jogarIA() {
    // Todas as combinações vencedoras possíveis
    static const int linhas[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},   // horizontais
        {0,3,6}, {1,4,7}, {2,5,8},   // verticais
        {0,4,8}, {2,4,6}              // diagonais
    };

    // --- 1. Tentar ganhar: procurar linha com 2 'O' e 1 vazio ---
    for (const auto& l : linhas) {
        int nVazios = 0, idxVazio = -1, nComputador = 0;
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro_[l[j]] == ' ')         { ++nVazios;    idxVazio = l[j]; }
            else if (tabuleiro_[l[j]] == COMPUTADOR) { ++nComputador; }
        }
        if (nVazios == 1 && nComputador == 2) {
            tabuleiro_[idxVazio] = COMPUTADOR;
            return;
        }
    }

    // --- 2. Bloquear: procurar linha com 2 'X' e 1 vazio ---
    for (const auto& l : linhas) {
        int nVazios = 0, idxVazio = -1, nJogador = 0;
        for (int j = 0; j < 3; ++j) {
            if (tabuleiro_[l[j]] == ' ')       { ++nVazios;  idxVazio = l[j]; }
            else if (tabuleiro_[l[j]] == JOGADOR) { ++nJogador; }
        }
        if (nVazios == 1 && nJogador == 2) {
            tabuleiro_[idxVazio] = COMPUTADOR;
            return;
        }
    }

    // --- 3. Jogada aleatória em casa livre ---
    std::array<int, 9> livres{};
    int nLivres = 0;
    for (int i = 0; i < 9; ++i) {
        if (tabuleiro_[i] == ' ') livres[nLivres++] = i;
    }
    if (nLivres > 0) {
        tabuleiro_[livres[rand() % nLivres]] = COMPUTADOR;
    }
}

// ------------------------------------------------------------
//  Mensagem 7 – verificarResultado
//  Devolve: 'J' jogador, 'C' computador, 'E' empate, ' ' continua
// ------------------------------------------------------------
char GaloController::verificarResultado() {
    static const int linhas[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };

    // Verificar se há vencedor
    for (const auto& l : linhas) {
        if (tabuleiro_[l[0]] != ' ' &&
            tabuleiro_[l[0]] == tabuleiro_[l[1]] &&
            tabuleiro_[l[1]] == tabuleiro_[l[2]]) {
            return (tabuleiro_[l[0]] == JOGADOR) ? 'J' : 'C';
        }
    }

    // Verificar empate (não há casas vazias)
    for (char c : tabuleiro_) {
        if (c == ' ') return ' ';  // ainda há jogo
    }
    return 'E';
}

// ------------------------------------------------------------
//  Mensagem 9 – setWins
//  Atualiza as vitórias do loggedClient.
//  TODO: substituir o cout pela chamada loggedClient.setWins()
//        quando a classe estiver disponível.
// ------------------------------------------------------------
void GaloController::setWins(int vitorias) {
    std::cout << "  [Sistema] Vitorias atualizadas: " << vitorias << "\n";
    // loggedClient.setWins(vitorias);  <-- ligar quando disponível
}
