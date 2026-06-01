#ifndef BLACKJACKVIEW_H
#define BLACKJACKVIEW_H

#include "../blackjack/blackjack.h"
#include <vector>
#include <string>

class BlackjackView {
public:
    void displayMenuPrincipal() const;
    void displayCriarUtilizador() const;
    void displayLogin() const;
    void displayHub(const std::string& username, double balance) const;
    void displayHands(const std::vector<Card>& playerHand, int pScore, const std::vector<Card>& dealerHand, int dScore, bool hideDealer) const;
    void displayPedirAposta() const;
    void displayOpcoesTurno() const;
    void displayResultado(int pScore, int dScore, bool playerBusted, double bet) const;
    void displayMensagem(const std::string& msg) const;
    void displaySaldo(double balance) const;
};

#endif