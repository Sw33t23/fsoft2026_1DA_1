#include <gtest/gtest.h>
#include "Container/JogadorContainer.h"

class JogadorContainerTest : public ::testing::Test {
protected:
    JogadorContainer container;
};


TEST_F(JogadorContainerTest, AddNewPlayerSuccess) {
    bool result = container.add("andre", "1234");
    
    EXPECT_TRUE(result);
    EXPECT_TRUE(container.usernameExiste("andre"));
}

TEST_F(JogadorContainerTest, AddDuplicateUsernameFails) {
    container.add("andre", "1234");
    bool result = container.add("andre", "abcd");
    
    EXPECT_FALSE(result);  // Deve falhar
}

TEST_F(JogadorContainerTest, UsernameExistsAfterAdd) {
    container.add("andre", "1234");
    
    EXPECT_TRUE(container.usernameExiste("andre"));
    EXPECT_FALSE(container.usernameExiste("diogo"));
}

TEST_F(JogadorContainerTest, UsernameDoesNotExist) {
    EXPECT_FALSE(container.usernameExiste("nonexistent"));
}

TEST_F(JogadorContainerTest, ValidateCorrectCredentials) {
    container.add("andre", "1234");
    
    Jogador* player = container.validarCredenciais("andre", "1234");
    
    EXPECT_NE(player, nullptr);
    EXPECT_EQ(player->username, "andre");
    EXPECT_EQ(player->password, "1234");
}

TEST_F(JogadorContainerTest, ValidateWrongPassword) {
    container.add("andre", "1234");
    
    Jogador* player = container.validarCredenciais("andre", "errada");
    
    EXPECT_EQ(player, nullptr);
}

TEST_F(JogadorContainerTest, ValidateNonexistentUsername) {
    Jogador* player = container.validarCredenciais("nonexistent", "1234");
    
    EXPECT_EQ(player, nullptr);
}

TEST_F(JogadorContainerTest, MultiplePlayersInContainer) {
    container.add("andre", "1234");
    container.add("diogo", "5678");
    container.add("goncalo", "9012");
    
    auto& players = container.getJogadores();
    EXPECT_EQ(players.size(), 3);
}

TEST_F(JogadorContainerTest, GetJogadoresNonEmpty) {
    container.add("andre", "1234");
    
    auto& players = container.getJogadores();
    EXPECT_GT(players.size(), 0);
    EXPECT_EQ(players[0].username, "andre");
}

TEST_F(JogadorContainerTest, GetJogadoresEmptyInitially) {
    auto& players = container.getJogadores();
    EXPECT_EQ(players.size(), 0);
}

TEST_F(JogadorContainerTest, SpecialCharactersInCredentials) {
    container.add("user@123", "pass!@#$");
    
    Jogador* player = container.validarCredenciais("user@123", "pass!@#$");
    EXPECT_NE(player, nullptr);
}