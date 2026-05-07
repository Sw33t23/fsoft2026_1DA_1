#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class Card {
public:
    string rank;
    int value;
    Card(string r, int v) : rank(r), value(v) {}
    void display() const { cout << "[" << rank << "]"; }
};

class Blackjack {
private:
    vector<Card> deck;
    vector<Card> playerHand;
    vector<Card> dealerHand;
    double balance; // User balance starts at 1000

    void initializeDeck() {
        string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
        int values[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
        deck.clear();
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 13; ++j) {
                deck.push_back(Card(ranks[j], values[j]));
            }
        }
        random_shuffle(deck.begin(), deck.end());
    }

    int calculateScore(vector<Card>& hand) {
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

    void displayHands(bool hideDealer) {
        cout << "\nDealer: ";
        if (hideDealer && !dealerHand.empty()) {
            dealerHand[0].display(); cout << " [?]";
        } else {
            for (auto& c : dealerHand) c.display();
            cout << " (Total: " << calculateScore(dealerHand) << ")";
        }
        cout << "\nPlayer: ";
        for (auto& c : playerHand) c.display();
        cout << " (Total: " << calculateScore(playerHand) << ")\n";
    }

public:
    // Constructor to set starting balance
    Blackjack() : balance(1000.0) {}

    void play() {
        srand(time(0));
        bool keepPlaying = true;

        while (keepPlaying && balance > 0) {
            cout << "\n================================" << endl;
            cout << "Current Balance: $" << balance << endl;

            // 1. Betting System
            int bet = 0;
            while (true) {
                cout << "Choose bet (10, 20, 50, 100): ";
                cin >> bet;
                if (bet == 10 || bet == 20 || bet == 50 || bet == 100) {
                    if (bet <= balance) break;
                    else cout << "Insufficient funds!" << endl;
                } else {
                    cout << "Invalid bet amount." << endl;
                }
            }

            initializeDeck();
            playerHand.clear();
            dealerHand.clear();

            // Initial Deal
            for (int i = 0; i < 2; i++) {
                playerHand.push_back(deck.back()); deck.pop_back();
                dealerHand.push_back(deck.back()); deck.pop_back();
            }

            // Player's Turn
            while (calculateScore(playerHand) < 21) {
                displayHands(true);
                cout << "Hit (h) or Stand (s)? ";
                char choice; cin >> choice;
                if (choice == 'h') {
                    playerHand.push_back(deck.back()); deck.pop_back();
                } else break;
            }

            int pScore = calculateScore(playerHand);
            bool playerBusted = (pScore > 21);

            if (!playerBusted) {
                // Dealer's Turn
                while (calculateScore(dealerHand) < 17) {
                    dealerHand.push_back(deck.back()); deck.pop_back();
                }
            }

            displayHands(false);
            int dScore = calculateScore(dealerHand);

            // 2. Settlement (Updating Balance)
            if (playerBusted) {
                cout << "Bust! You lose $" << bet << endl;
                balance -= bet;
            } else if (dScore > 21 || pScore > dScore) {
                cout << "WIN! You gained $" << bet << endl;
                balance += bet;
            } else if (pScore < dScore) {
                cout << "Dealer wins! You lose $" << bet << endl;
                balance -= bet;
            } else {
                cout << "Push! Bet returned." << endl;
            }

            // 3. Keep Playing Logic
            if (balance > 0) {
                cout << "\nPlay another round? (y/n): ";
                char again; cin >> again;
                if (again != 'y') keepPlaying = false;
            } else {
                cout << "You're out of money! Game Over." << endl;
                keepPlaying = false;
            }
        }
        cout << "Final Balance: $" << balance << "\nThanks for playing!" << endl;
    }
};

int main() {
    Blackjack game;
    game.play();
    return 0;
}