#include <gtest/gtest.h>
#include "../GamesPlatform/Headers/Model/Ranking.h"

class RankingTest : public ::testing::Test {
protected:
    Ranking ranking;
};

TEST_F(RankingTest, NewEntryInMaiorMenorRanking) {
    ranking.atualizarMaiorMenor("andre", 5);

    auto entries = ranking.getMaiorMenor();
    EXPECT_EQ(entries.size(), 1);
    EXPECT_EQ(entries[0].username, "andre");
    EXPECT_EQ(entries[0].valor, 5);
}

TEST_F(RankingTest, UpdateToLessTries) {
    ranking.atualizarMaiorMenor("andre", 5);
    ranking.atualizarMaiorMenor("andre", 3);

    auto entries = ranking.getMaiorMenor();
    EXPECT_EQ(entries.size(), 1);
    EXPECT_EQ(entries[0].username, "andre");
    EXPECT_EQ(entries[0].valor, 3);
}

TEST_F(RankingTest, WorseValueDoesNotReplace) {
    ranking.atualizarMaiorMenor("diogo", 3);
    ranking.atualizarMaiorMenor("diogo", 8);

    auto entries = ranking.getMaiorMenor();
    EXPECT_EQ(entries.size(), 1);
    EXPECT_EQ(entries[0].valor, 3);
}

TEST_F(RankingTest, MaiorMenorAscendingOrder) {
    ranking.atualizarMaiorMenor("andre", 5);
    ranking.atualizarMaiorMenor("diogo", 2);
    ranking.atualizarMaiorMenor("goncalo", 8);

    auto entries = ranking.getMaiorMenor();
    EXPECT_EQ(entries[0].username, "diogo");
    EXPECT_EQ(entries[1].username, "andre");
    EXPECT_EQ(entries[2].username, "goncalo");
}


TEST_F(RankingTest, BlackjackDescendingOrder) {
    ranking.atualizarBlackjack("andre", 1000);
    ranking.atualizarBlackjack("diogo", 1500);
    ranking.atualizarBlackjack("goncalo", 800);

    auto entries = ranking.getBlackjack();
    EXPECT_EQ(entries[0].username, "diogo");
    EXPECT_EQ(entries[1].username, "andre");
    EXPECT_EQ(entries[2].username, "goncalo");
}


TEST_F(RankingTest, MaxTenEntries) {
    for (int i = 0; i < 15; i++) {
        ranking.atualizarBlackjack("player" + std::to_string(i), 1000 - i * 50);
    }

    auto entries = ranking.getBlackjack();
    EXPECT_LE(entries.size(), 10);
}

TEST_F(RankingTest, MultiplePlayersInRanking) {
    ranking.atualizarGalo("andre", 5);
    ranking.atualizarGalo("diogo", 3);
    ranking.atualizarGalo("goncalo", 7);

    auto entries = ranking.getGalo();
    EXPECT_EQ(entries.size(), 3);
}

TEST_F(RankingTest, EmptyRanking) {
    auto blackjack = ranking.getBlackjack();
    auto maiorMenor = ranking.getMaiorMenor();
    auto galo = ranking.getGalo();

    EXPECT_EQ(blackjack.size(), 0);
    EXPECT_EQ(maiorMenor.size(), 0);
    EXPECT_EQ(galo.size(), 0);
}

TEST_F(RankingTest, IndependentRankings) {
    ranking.atualizarBlackjack("andre", 1000);
    ranking.atualizarMaiorMenor("andre", 5);
    ranking.atualizarGalo("andre", 10);
    
    auto bj = ranking.getBlackjack();
    auto mm = ranking.getMaiorMenor();
    auto galo = ranking.getGalo();
    
    EXPECT_EQ(bj.size(), 1);
    EXPECT_EQ(mm.size(), 1);
    EXPECT_EQ(galo.size(), 1);
}