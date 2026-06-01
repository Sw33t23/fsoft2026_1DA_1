#include "BlackjackView.h"
#include <iostream>

void BlackjackView::displayMenuPrincipal() const {
    std::cout << "\n=== CASINO PLATFORM ===\n1. Criar Conta\n2. Login\n3. Sair\nEscolha: ";
}
void BlackjackView::displayCriarUtilizador() const { std::cout << "\n[REGISTO] Insira o nome do novo utilizador: "; }
void BlackjackView::displayLogin() const { std::cout << "\n[LOGIN] Insira o seu nome de utilizador: "; }

void BlackjackView::displayHub(const std::string& username, double balance) const {
    std::cout << "\n=======================================================";
    std::cout << "\nMENU PRINCIPAL | Utilizador: " << username << " | Saldo: $" << balance;
    std::cout << "\n=======================================================";
    std::cout << "\n1. Jogar Maior ou Menor\n2. Jogar Blackjack\n3. Jogar Jogo do Galo\n4. Terminar Sessao (Logout)\nEscolha uma opcao: ";
}

void BlackjackView::displayHands(const std::vector<Card>& playerHand, int pScore, const std::vector<Card>& dealerHand, int dScore, bool hideDealer) const {
    std::cout << "\nDealer: ";
    if (hideDealer && !dealerHand.empty()) {
        std::cout << "[" << dealerHand[0].rank << "] [?]";
    } else {
        for (const auto& c : dealerHand) std::cout << "[" << c.rank << "] ";
        std::cout << "(Total: " << dScore << ")";
    }
    std::cout << "\nJogador: ";
    for (const auto& c : playerHand) std::cout << "[" << c.rank << "] ";
    std::cout << "(Total: " << pScore << ")\n";
}

void BlackjackView::displayPedirAposta() const { std::cout << "Insira a sua aposta (10, 20, 50, 100): "; }
void BlackjackView::displayOpcoesTurno() const { std::cout << "Deseja (h)it / pedir carta ou (s)tand / parar? "; }

void BlackjackView::displayResultado(int pScore, int dScore, bool playerBusted, double bet) const {
    if (playerBusted) std::cout << "\n--- Bust! Ultrapassou 21. Perdeu $" << bet << " ---\n";
    else if (dScore > 21 || pScore > dScore) std::cout << "\n--- Ganhou a rodada! Recebeu $" << bet << " ---\n";
    else if (pScore < dScore) std::cout << "\n--- O Dealer Ganhou! Perdeu $" << bet << " ---\n";
    else std::cout << "\n--- Empate (Push)! A sua aposta foi devolvida. ---\n";
}

void BlackjackView::displayMensagem(const std::string& msg) const { std::cout << msg << std::endl; }

void BlackjackView::displaySaldo(double balance) const {
    std::cout << "\nSaldo Disponivel: $" << balance << std::endl;
}