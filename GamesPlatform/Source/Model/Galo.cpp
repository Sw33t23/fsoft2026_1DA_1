#include "../../Headers/Model/Galo.h"
#include <cstdlib>
#include <ctime>

Galo::Galo(char simJogador) : simboloJogador(simJogador), vitorias(0) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';

    simboloIA = (simJogador == 'X') ? 'O' : 'X';
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

bool Galo::validarEJogar(int linha, int coluna) {
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) return false;
    if (tabuleiro[linha][coluna] != ' ') return false;
    
    tabuleiro[linha][coluna] = simboloJogador;
    return true;
}

void Galo::jogarComputador() {
    std::vector<std::pair<int,int>> livres;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') livres.push_back({i, j});
        }
    }
    if (livres.empty()) return;

    int idx = std::rand() % livres.size();
    tabuleiro[livres[idx].first][livres[idx].second] = simboloIA;
}

bool Galo::verificarVencedor(char simbolo) const {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == simbolo && tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo) return true;
        if (tabuleiro[0][i] == simbolo && tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo) return true;
    }
    if (tabuleiro[0][0] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo) return true;
    if (tabuleiro[0][2] == simbolo && tabuleiro[1][1] == simbolo && tabuleiro[2][0] == simbolo) return true;
    return false;
}

bool Galo::tabuleiroCheio() const {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == ' ') return false;
    return true;
}

char Galo::verificarResultado() const {
    if (verificarVencedor(simboloJogador)) return 'J';
    if (verificarVencedor(simboloIA)) return 'I';
    if (tabuleiroCheio()) return 'E';
    return ' ';
}

bool Galo::jogoAtivo() const {
    return verificarResultado() == ' ';
}

void Galo::incrementarVitorias() { vitorias++; }
int Galo::getVitorias() const { return vitorias; }
const char (*Galo::getTabuleiro() const)[3] { return tabuleiro; }
char Galo::getSimboloJogador() const { return simboloJogador; }
char Galo::getSimboloIA() const { return simboloIA; }