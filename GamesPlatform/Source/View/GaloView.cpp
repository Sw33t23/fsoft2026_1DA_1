// ============================================================
//  GaloView.cpp  –  Implementação da View do Jogo do Galo
// ============================================================

#include "../../Headers/View/GaloView.h"
#include "../../Headers/Exception/GaloException.h"  // <-- include do Utils
#include <iostream>
#include <array>

// Mensagem 1 – menuPrincipal
bool GaloView::menuPrincipal(const std::string& nomeJogador) {
    std::cout << "\n========================================\n";
    std::cout << "  Ola, " << nomeJogador << "!\n";
    std::cout << "  Bem-vindo ao Jogo do Galo!\n";
    std::cout << "========================================\n";
    std::cout << "  1 - Jogar\n";
    std::cout << "  0 - Voltar ao menu principal\n";
    std::cout << "========================================\n";

    int opcao = GaloUtils::getInt("  Opcao: ");
    return (opcao == 1);
}

// Mensagem 2 – mostrarInstrucoes
void GaloView::mostrarInstrucoes() {
    std::cout << "\n--- INSTRUCOES ---\n";
    std::cout << "  Tu jogas com 'X', o computador joga com 'O'.\n";
    std::cout << "  Escolhe uma posicao de 1 a 9:\n\n";
    std::cout << "    1 | 2 | 3\n";
    std::cout << "   ---+---+---\n";
    std::cout << "    4 | 5 | 6\n";
    std::cout << "   ---+---+---\n";
    std::cout << "    7 | 8 | 9\n\n";
    std::cout << "  Alinha 3 simbolos em linha, coluna ou diagonal para ganhar!\n";
    std::cout << "------------------\n\n";
}

// Mensagem 3 – pedirPosicao
int GaloView::pedirPosicao() {
    return GaloUtils::getInt("  A tua jogada (1-9): ");
}

// Mensagem 5 – mostrarTabuleiro
void GaloView::mostrarTabuleiro(const std::array<char, 9>& tabuleiro) {
    std::cout << "\n";
    for (int i = 0; i < 9; ++i) {
        char celula = tabuleiro[i];
        if (celula == ' ') {
            std::cout << " " << (i + 1);
        } else {
            std::cout << " " << celula;
        }
        if ((i + 1) % 3 == 0) {
            std::cout << "\n";
            if (i < 6) std::cout << "  --+---+--\n";
        } else {
            std::cout << " |";
        }
    }
    std::cout << "\n";
}

// Feedback de jogada (mensagem 4)
void GaloView::mostrarFeedbackJogada(int posicao, bool valida) {
    if (valida) {
        std::cout << "  Jogaste na casa " << posicao << ".\n";
    } else {
        std::cout << "  [Erro] Posicao invalida ou ja ocupada. Tenta outra.\n";
    }
}

// Aviso de jogada do computador (mensagem 6)
void GaloView::mostrarJogadaComputador() {
    std::cout << "  O computador esta a pensar...\n";
}

// Mensagem 8 – mostrarResultadoFinal
void GaloView::mostrarResultadoFinal(char resultado, const std::string& nomeJogador) {
    std::cout << "\n========================================\n";
    if (resultado == 'J') {
        std::cout << "  PARABENS, " << nomeJogador << "! Ganhaste! :)\n";
    } else if (resultado == 'C') {
        std::cout << "  O computador ganhou. Melhor sorte proxima vez!\n";
    } else {
        std::cout << "  Empate! Boa partida!\n";
    }
    std::cout << "========================================\n\n";
}

// Pergunta se quer jogar de novo
bool GaloView::perguntarJogarDeNovo() {
    int opcao = GaloUtils::getInt("  Jogar outra vez? (1 = Sim / 0 = Nao): ");
    return (opcao == 1);
}

// Mostra vitórias da sessão (mensagem 9)
void GaloView::mostrarVitorias(const std::string& nomeJogador, int vitorias) {
    std::cout << "  Obrigado por jogar, " << nomeJogador << "!\n";
    std::cout << "  Vitorias registadas nesta sessao: " << vitorias << "\n\n";
}
