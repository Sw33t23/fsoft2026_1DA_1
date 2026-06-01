#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <vector>
#include <string>

struct Card {
    std::string rank;
    int value;
};

class Blackjack {
private:
    std::vector<Card> deck;
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;
    double balance;

public:
    Blackjack(double startingBalance);
    void initializeDeck();
    int calculateScore(const std::vector<Card>& hand);
    void hitPlayer();
    void hitDealer();
    void clearHands();

    std::vector<Card> getPlayerHand() const { return playerHand; }
    std::vector<Card> getDealerHand() const { return dealerHand; }
    double getBalance() const { return balance; }
    void setBalance(double b) { balance = b; }
};

#endif