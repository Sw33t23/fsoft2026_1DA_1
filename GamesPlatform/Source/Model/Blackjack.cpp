#include "../../Headers/Model/Blackjack.h"
#include <algorithm>
#include <random>
#include <ctime>

Blackjack::Blackjack(double startingBalance) : balance(startingBalance) {
    srand(time(0));
}

void Blackjack::initializeDeck() {
    std::string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    deck.clear();
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            deck.push_back({ranks[j], values[j]});
        }
    }
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(std::time(0)));
}

int Blackjack::calculateScore(const std::vector<Card>& hand) {
    int score = 0, aces = 0;
    for (const auto& card : hand) {
        score += card.value;
        if (card.rank == "A") aces++;
    }
    while (score > 21 && aces > 0) {
        score -= 10;
        aces--;
    }
    return score;
}

void Blackjack::hitPlayer() { playerHand.push_back(deck.back()); deck.pop_back(); }
void Blackjack::hitDealer() { dealerHand.push_back(deck.back()); deck.pop_back(); }
void Blackjack::clearHands() { playerHand.clear(); dealerHand.clear(); }