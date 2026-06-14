#include <gtest/gtest.h>
#include "Model/MaiorOuMenor.h"
 
class MaiorOuMenorTest : public ::testing::Test {
protected:
    MaiorOuMenor game;

    int findSecretNumber(MaiorOuMenor& g) {
        int left = 1, right = 100;
        while (left <= right) {
            int mid = (left + right) / 2;
            int result = g.verificarPalpite(mid);
            if (result == 0) return mid;
            if (result == 1) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};
 

TEST_F(MaiorOuMenorTest, GuessEqualsSecretNumber) {
    game.iniciarJogoNovo();
    int secretNumber = findSecretNumber(game);

    game.iniciarJogoNovo();
    int result = game.verificarPalpite(secretNumber);
    
    EXPECT_EQ(result, 0);
    EXPECT_EQ(game.getTentativasAtuais(), 1);
}
 

TEST_F(MaiorOuMenorTest, GuessGreaterThanSecretNumber) {
    game.iniciarJogoNovo();
    int secretNumber = findSecretNumber(game);
    
    game.iniciarJogoNovo();
    int guessGreater = secretNumber + 10;
    if (guessGreater > 100) guessGreater = 100;
    
    int result = game.verificarPalpite(guessGreater);
    EXPECT_EQ(result, 1);
    EXPECT_EQ(game.getTentativasAtuais(), 1);
}

TEST_F(MaiorOuMenorTest, GuessSmallerThanSecretNumber) {
    game.iniciarJogoNovo();
    int secretNumber = findSecretNumber(game);
    
    game.iniciarJogoNovo();
    int guessSmaller = secretNumber > 10 ? secretNumber - 10 : 1;
    
    int result = game.verificarPalpite(guessSmaller);
    EXPECT_EQ(result, -1);
    EXPECT_EQ(game.getTentativasAtuais(), 1);
}

TEST_F(MaiorOuMenorTest, GuessAboveMaxLimit) {
    game.iniciarJogoNovo();
    try {
        game.verificarPalpite(101);
        EXPECT_EQ(game.getTentativasAtuais(), 0);
    } catch (...) {
        SUCCEED();
    }
}
 

TEST_F(MaiorOuMenorTest, CountAttemptsAccumulately) {
    game.iniciarJogoNovo();
    int secretNumber = findSecretNumber(game);
    
    game.iniciarJogoNovo();
    game.verificarPalpite(50);
    EXPECT_EQ(game.getTentativasAtuais(), 1);
    
    game.verificarPalpite(25);
    EXPECT_EQ(game.getTentativasAtuais(), 2);
    
    game.verificarPalpite(75);
    EXPECT_EQ(game.getTentativasAtuais(), 3);
}
 

TEST_F(MaiorOuMenorTest, GetMaxLimitReturns100) {
    game.iniciarJogoNovo();
    EXPECT_EQ(game.getLimiteMax(), 100);
}
 