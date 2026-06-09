#include "RankingView.h"
#include <iostream>
 
void RankingView::exibirTop10(const std::vector<EntradaRanking>& lista,
                               const std::string& nomeJogo,
                               const std::string& colunaValor) {
    std::cout << "\n=== TOP 10 - " << nomeJogo << " ===\n";
 
    if (lista.empty()) {
        std::cout << "Sem registos ainda.\n";
    } else {
        for (int i = 0; i < (int)lista.size(); i++) {
            std::cout << (i + 1) << ". "
                      << lista[i].username
                      << " - " << colunaValor << ": "
                      << lista[i].valor << "\n";
        }
    }
    std::cout << "\n";
}
 
int RankingView::pedirOpcaoMenu() {
    int opcao;
    std::cout << "\n--- RANKING ---\n"
              << "1. Blackjack\n"
              << "2. Galo\n"
              << "3. Maior ou Menor\n"
              << "0. Voltar\n"
              << "Opcao: ";
    std::cin >> opcao;
    return opcao;
}
 
void RankingView::mostrarOpcaoInvalida() {
    std::cout << "Opcao invalida.\n";
}
 
void RankingView::mostrarAVoltar() {
    std::cout << "A voltar ao menu principal...\n";
}
