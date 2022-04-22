#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "player.hh"
#include "balda.hh"

TEST(PlayerTest, createEmptyPlayer)
{
    Player player = Player{};
    std::stringstream ss;
    ss << player;
    std::string player_str = ss.str();
    ASSERT_EQ(player_str, "0"); 
}

TEST(PlayerTest, createFilledPlayer)
{
    Player player = Player{};
    player.increase_score(11);
    player.add_word("cool");
    player.add_word("banana");

    std::stringstream ss;
    ss << player;
    std::string player_str = ss.str();
    ASSERT_EQ(player_str, "11coolbanana"); 
}

TEST(BaldaTest, createGame)
{
    std::vector<std::string> words = {"addd", "asss"};
    std::string word = "adddd";
    Balda balda = Balda{word, words};
    std::stringstream ss;
    ss << balda;
    std::string balda_str = ss.str();
    ASSERT_EQ(balda_str, "adddasss0000000000adddd0000000000"); 
}
