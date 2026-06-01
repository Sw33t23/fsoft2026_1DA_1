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



#endif