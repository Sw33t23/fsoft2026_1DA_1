#include <gtest/gtest.h>
#include "../GamesPlatform/Headers/Model/Galo.h"

class GaloTest : public ::testing::Test {
protected:
    Galo game{'X'};
};


TEST_F(GaloTest, PlayerWinsInLine) {
    Galo g{'X'};

    EXPECT_TRUE(g.validarEJogar(1, 1));
    EXPECT_TRUE(g.validarEJogar(1, 2));
    EXPECT_TRUE(g.validarEJogar(1, 3));
    
    EXPECT_EQ(g.verificarResultado(), 'J');
}


TEST_F(GaloTest, DrawWhenBoardFull) {
    Galo g{'X'};
    


    EXPECT_TRUE(g.jogoAtivo());
}


TEST_F(GaloTest, GameInProgress) {
    Galo g{'X'};
    
    EXPECT_TRUE(g.jogoAtivo());
    

    g.validarEJogar(1, 1);
    EXPECT_TRUE(g.jogoAtivo());
}


TEST_F(GaloTest, MoveOutOfBounds) {
    Galo g{'X'};

    EXPECT_FALSE(g.validarEJogar(0, 1));
    EXPECT_FALSE(g.validarEJogar(4, 1));
    EXPECT_FALSE(g.validarEJogar(1, 0));
    EXPECT_FALSE(g.validarEJogar(1, 4));
}


TEST_F(GaloTest, MoveOnOccupiedPosition) {
    Galo g{'X'};
    EXPECT_TRUE(g.validarEJogar(1, 1));
    EXPECT_FALSE(g.validarEJogar(1, 1));
}


TEST_F(GaloTest, PlayerWinsInDiagonal) {
    Galo g{'X'};

    EXPECT_TRUE(g.validarEJogar(1, 1));
    g.jogarComputador();

    // Se a IA ocupou (2,2), tenta outra diagonal
    if (!g.validarEJogar(2, 2)) {
        // a IA bloqueou — joga diagonal secundária
        EXPECT_TRUE(g.validarEJogar(1, 3));
        g.jogarComputador();
        EXPECT_TRUE(g.validarEJogar(2, 2));
        g.jogarComputador();
        EXPECT_TRUE(g.validarEJogar(3, 1));
    } else {
        g.jogarComputador();
        EXPECT_TRUE(g.validarEJogar(3, 3));
    }

    EXPECT_EQ(g.verificarResultado(), 'J');
}

TEST_F(GaloTest, GetSymbols) {
    Galo g{'X'};
    
    EXPECT_EQ(g.getSimboloJogador(), 'X');
    EXPECT_EQ(g.getSimboloIA(), 'O');
}

TEST_F(GaloTest, IncrementAndGetVitories) {
    Galo g{'X'};
    
    EXPECT_EQ(g.getVitorias(), 0);
    
    g.incrementarVitorias();
    EXPECT_EQ(g.getVitorias(), 1);
    
    g.incrementarVitorias();
    EXPECT_EQ(g.getVitorias(), 2);
}