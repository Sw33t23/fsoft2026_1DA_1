#include "../../Headers/Model/Galo.h"
#include <cstdlib>
#include <ctime>

Galo::Galo(char simJogador) : simboloJogador(simJogador), vitorias(0) {
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            tabuleiro[i][j] = ' ';

    simboloIA = (simJogador == 'X') ? 'O' : 'X';
    std::srand(static_cast<unsigned>(std::time(nullptr)));
}

bool Galo::validarEJogar(int linha, int coluna) {
    if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) return false;
    if (tabuleiro[linha][coluna] != ' ') return false;
    
    tabuleiro[linha][coluna] = simboloJogador;
    return true;
}

void Galo::jogarComputador() {
    std::vector<std::pair<int,int>> livres;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (tabuleiro[i][j] == ' ') livres.push_back({i, j});
        }
    }
    if (livres.empty()) return;

    int idx = std::rand() % livres.size();
    tabuleiro[livres[idx].first][livres[idx].second] = simboloIA;
}

bool Galo::verificarVencedor(char simbolo) const {
    for (int i = 1; i <= 3; i++) {
        if (tabuleiro[i][1] == simbolo && tabuleiro[i][2] == simbolo && tabuleiro[i][3] == simbolo) return true;
        if (tabuleiro[1][i] == simbolo && tabuleiro[2][i] == simbolo && tabuleiro[3][i] == simbolo) return true;
    }
    if (tabuleiro[1][1] == simbolo && tabuleiro[2][2] == simbolo && tabuleiro[3][3] == simbolo) return true;
    if (tabuleiro[1][3] == simbolo && tabuleiro[2][2] == simbolo && tabuleiro[3][1] == simbolo) return true;
    return false;
}

bool Galo::tabuleiroCheio() const {
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
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
const char (*Galo::getTabuleiro() const)[4] { return tabuleiro; }
char Galo::getSimboloJogador() const { return simboloJogador; }
char Galo::getSimboloIA() const { return simboloIA; }