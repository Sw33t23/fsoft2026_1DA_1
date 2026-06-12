#include "../../Headers/View/BlackjackView.h"
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

// Interface Inicial do Blackjack combinando com o padrão do Maior ou Menor
void BlackjackView::displayHands(const std::vector<Card>& playerHand, int pScore, const std::vector<Card>& dealerHand, int dScore, bool hideDealer) const {
    // Só mostra o cabeçalho estético quando o jogo inicia (mãos vazias)
    if (playerHand.empty() && dealerHand.empty()) {
        std::cout << "\n=========================================\n";
        std::cout << "                BLACKJACK                \n";
        std::cout << "=========================================\n";
        std::cout << "REGRAS:\n";
        std::cout << "- Aproxime-se o mais possivel dos 21 pontos sem ultrapassar\n";
        std::cout << "- O Dealer para obrigatoriamente aos 17 pontos\n";
        std::cout << "=========================================\n";
        return;
    }

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

void BlackjackView::displayPedirAposta() const { std::cout << "Introduza o valor da sua aposta (10, 20, 50, 100): "; }

// Frase de opções melhorada e mais limpa
void BlackjackView::displayOpcoesTurno() const { std::cout << "Deseja pedir carta (h) ou parar (s)? "; }

// Mensagem de vitória corrigida para mostrar o retorno total (dobro do apostado)
void BlackjackView::displayResultado(int pScore, int dScore, bool playerBusted, double bet) const {
    if (playerBusted) {
        std::cout << "\n--- Bust! Ultrapassou os 21 pontos. Perdeu $" << bet << " ---\n";
    }
    else if (dScore > 21 || pScore > dScore) {
        std::cout << "\n--- Parabens, ganhou! Recebeu o dobro: $" << (bet * 2) << " ---\n";
    }
    else if (pScore < dScore) {
        std::cout << "\n--- O Dealer ganhou a rodada. Perdeu $" << bet << " ---\n";
    }
    else {
        std::cout << "\n--- Empate! A sua aposta de $" << bet << " foi devolvida. ---\n";
    }
}

void BlackjackView::displayMensagem(const std::string& msg) const { std::cout << msg << std::endl; }

void BlackjackView::displaySaldo(double balance) const {
    std::cout << "\n-----------------------------------------";
    std::cout << "\nSaldo Atual: $" << balance;
    std::cout << "\n-----------------------------------------\n";
}

bool BlackjackView::pedirDesejaJogarNovamente() const {
    std::cout << "\nDeseja jogar novamente?\n";
    std::cout << " 1 - Sim\n";
    std::cout << " 0 - Nao\n\n";
    std::cout << "Opcao: ";

    int opcao;
    while (!(std::cin >> opcao) || (opcao != 0 && opcao != 1)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Opcao invalida (0 ou 1): ";
    }
    std::cin.ignore(10000, '\n');
    return opcao == 1;
}