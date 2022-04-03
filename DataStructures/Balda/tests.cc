#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "player.hh"

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