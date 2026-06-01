#include <iostream>
#include <string>
#include <climits>

char tabuleiro[3][3];
int vitorias = 0;
std::string nomeJogador;


int main() {
    std::cout << "Bem-vindo ao Jogo do Galo!\nIntroduza o seu nome: ";
    std::getline(std::cin, nomeJogador);
    if (nomeJogador.empty()) nomeJogador = "Jogador";
    std::cout << "\n=========================================\n";
    std::cout << "                 JOGO DO GALO    \n";
    std::cout << "=========================================\n";
    std::cout << "  Voce joga com 'X', a IA joga com 'O'.\n";
    std::cout << "  Introduza a linha (1-3) e a coluna (1-3).\n";
    std::cout << "=========================================\n";
}