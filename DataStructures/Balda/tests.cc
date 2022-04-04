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
    std::list<std::string> words = {"addd", "asss"};
    std::string word = "adddd";
    Balda balda = Balda{word, words};
    std::stringstream ss;
    ss << balda;
    std::string balda_str = ss.str();
    ASSERT_EQ(balda_str, "adddasss0000000000adddd0000000000"); 
}

TEST(CellTest, createEmptyCell)
{
    Cell cell = Cell{};
    std::stringstream ss;
    ss << cell;
    std::string cell_str = ss.str();
    ASSERT_EQ(cell_str, "00"); 
}

TEST(CellTest, readCell)
{
    Cell cell = Cell();
    std::string data = "1 1";
    std::stringstream ss(data);
    ss >> cell;
    std::stringstream ss1;
    ss1 << cell;
    std::string s = ss1.str();
    EXPECT_EQ(s, "11");
}

TEST(CellTest, copyCell)
{
    Cell cell1 = Cell(3, 2);
    Cell cell2 = cell1;
    std::stringstream ss1;
    ss1 << cell2;
    std::string s = ss1.str();
    EXPECT_EQ(s, "32");
}
