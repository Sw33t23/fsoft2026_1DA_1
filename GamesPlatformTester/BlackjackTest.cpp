#include <gtest/gtest.h>
#include "../GamesPlatform/Headers/Model/Blackjack.h"

class BlackjackTest : public ::testing::Test {
protected:
    Blackjack game{1000.0};
};

TEST_F(BlackjackTest, SimpleSumWithoutAces) {
    std::vector<Card> hand = {
        {"10", 10},
        {"7", 7}
    };
    
    int score = game.calculateScore(hand);
    EXPECT_EQ(score, 17);
}


TEST_F(BlackjackTest, AceCountedAs11) {
    std::vector<Card> hand = {
        {"A", 11},
        {"K", 10}
    };
    
    int score = game.calculateScore(hand);
    EXPECT_EQ(score, 21);
}


TEST_F(BlackjackTest, AceReducedToAvoidBust) {
    std::vector<Card> hand = {
        {"A", 11},
        {"A", 11},
        {"9", 9}
    };
    
    int score = game.calculateScore(hand);
    EXPECT_EQ(score, 21);
}


TEST_F(BlackjackTest, HandAbove21) {
    std::vector<Card> hand = {
        {"10", 10},
        {"10", 10},
        {"5", 5}
    };
    
    int score = game.calculateScore(hand);
    EXPECT_EQ(score, 25);
}


TEST_F(BlackjackTest, EmptyHand) {
    std::vector<Card> hand = {};
    
    int score = game.calculateScore(hand);
    EXPECT_EQ(score, 0);
}


TEST_F(BlackjackTest, MultipleAcesAdjusted) {
    std::vector<Card> hand = {
        {"A", 11},
        {"A", 11},
        {"A", 11},
        {"8", 8}
    };
    

    int score = game.calculateScore(hand);
    EXPECT_EQ(score, 21);
}


TEST_F(BlackjackTest, GetBalance) {
    EXPECT_EQ(game.getBalance(), 1000.0);
}


TEST_F(BlackjackTest, SetBalance) {
    game.setBalance(750.0);
    EXPECT_EQ(game.getBalance(), 750.0);
}