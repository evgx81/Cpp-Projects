#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "set.hh"

TEST(SetTests, create_empty_set)
{
    Set<int> set = Set<int>();
    std::stringstream ss;
    ss << set;
    std::string s = ss.str();
    EXPECT_EQ(s, "Множество пусто\n");
}

TEST(SetTests, create_not_empty_set)
{
    Set<int> set = Set<int>();
    set.insert(1);
    set.insert(2);
    set.insert(3);
    set.insert(4);
    std::stringstream ss1;
    ss1 << set;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Количество элементов: 4\nЭлементы: 1 2 3 4 \n");
}

TEST(SetTests, copy_set)
{
    Set<int> set1 = Set<int>();
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);
    Set<int> set2 = set1;

    std::stringstream ss1;
    ss1 << set2;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Количество элементов: 5\nЭлементы: 1 2 3 4 5 \n");
}

TEST(SetTests, erase_leem)
{
    Set<int> set;
    set.insert(1);
    set.insert(30);
    set.insert(2);
    set.insert(3);
    set.insert(45);

    set.erase(45);
    std::stringstream ss1;
    ss1 << set;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Количество элементов: 4\nЭлементы: 1 30 2 3 \n");
}

TEST(SetTests, erase_all_elems)
{
    Set<int> set;
    set.insert(1);

    set.erase(1);
    std::stringstream ss1;
    ss1 << set;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Множество пусто\n");
}

TEST(SetTests, set_union)
{
    Set<int> set1 = Set<int>();
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);
    std::cout << set1;
    Set<int> set2 = Set<int>();
    set2.insert(4);
    set2.insert(5);
    set2.insert(6);
    set2.insert(7);
    set2.insert(8);
    set2.insert(9);
    std::cout << set2;
    Set<int> set3 = set1.set_union(set2);

    std::stringstream ss1;
    ss1 << set3;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Количество элементов: 9\nЭлементы: 1 2 3 4 5 6 7 8 9 \n");
}

TEST(SetTests, empty_set_union)
{
    Set<int> set1 = Set<int>();
    std::cout << set1;
    Set<int> set2 = Set<int>();
    std::cout << set2;
    Set<int> set3 = set1.set_union(set2);

    std::stringstream ss1;
    ss1 << set3;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Множество пусто\n");
}

TEST(SetTests, set_intersection)
{
    Set<int> set1 = Set<int>();
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);
    std::cout << set1;
    Set<int> set2 = Set<int>();
    set2.insert(4);
    set2.insert(5);
    set2.insert(6);
    set2.insert(7);
    set2.insert(8);
    set2.insert(9);
    std::cout << set2;
    Set<int> set3 = set1.set_intersection(set2);

    std::stringstream ss1;
    ss1 << set3;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Количество элементов: 2\nЭлементы: 4 5 \n");

}

TEST(SetTests, empty_set_intersection)
{
    Set<int> set1 = Set<int>();
    std::cout << set1;
    Set<int> set2 = Set<int>();
    set2.insert(6);
    set2.insert(7);
    set2.insert(8);
    set2.insert(9);
    std::cout << set2;
    Set<int> set3 = set1.set_intersection(set2);

    std::stringstream ss1;
    ss1 << set3;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Множество пусто\n");
}

TEST(SetTests, set_difference)
{
    Set<int> set1 = Set<int>();
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);
    std::cout << set1;
    Set<int> set2 = Set<int>();
    set2.insert(4);
    set2.insert(5);
    set2.insert(6);
    set2.insert(7);
    set2.insert(8);
    set2.insert(9);
    std::cout << set2;
    Set<int> set3 = set1.set_difference(set2);

    std::stringstream ss1;
    ss1 << set3;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Количество элементов: 3\nЭлементы: 1 2 3 \n");
}

TEST(SetTests, empty_set_difference)
{
    Set<int> set1 = Set<int>();
    std::cout << set1;
    Set<int> set2 = Set<int>();
    set2.insert(6);
    set2.insert(7);
    set2.insert(8);
    set2.insert(9);
    std::cout << set2;
    Set<int> set3 = set1.set_difference(set2);

    std::stringstream ss1;
    ss1 << set3;
    std::string s = ss1.str();
    EXPECT_EQ(s, "Множество пусто\n");
}

TEST(SetTests, getSize)
{
    Set<int> set = Set<int>();
    set.insert(1);
    set.insert(2);
    set.insert(3);
    int size = set.size();
    EXPECT_EQ(size, 3);
}

TEST(SetTests, findElemInSet)
{
    Set<int> set1 = Set<int>();
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);

    bool flag = set1.find(9);
    EXPECT_EQ(flag, false);
}

TEST(SetTests, is_subset)
{
    Set<int> set1 = Set<int>();
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);
    set1.insert(3);
    set1.insert(4);
    set1.insert(5);
    Set<int> set2 = Set<int>();
    set2.insert(1);
    set2.insert(2);
    set2.insert(3);
    set2.insert(3);
    set2.insert(4);
    set2.insert(5);
    
    bool flag = set1.is_subset(set2);
    EXPECT_EQ(flag, true);
}