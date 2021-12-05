#include <gtest/gtest.h>

#include "my_utils.h"

TEST(Tests, FactorialTestRecursive1) {
    EXPECT_EQ(factRecursive(-1), 0);
}
TEST(Tests, FactorialTestRecursive2) {
    EXPECT_EQ(factRecursive(0), 1);
}
TEST(Tests, FactorialTestRecursive3) {
    EXPECT_EQ(factRecursive(1), 1);
}
TEST(Tests, FactorialTestRecursive4) {
    EXPECT_EQ(factRecursive(2), 2);
}
TEST(Tests, FactorialTestRecursive5) {
    EXPECT_EQ(factRecursive(5), 120);
}
TEST(Tests, FactorialTestRecursive6) {
    EXPECT_EQ(factRecursive(10), 3628800);
}
TEST(Tests, FactorialTestRecursive7) {
    EXPECT_EQ(factRecursive(15), 1307674368000);
}

TEST(Tests, FactorialTestCycle1) {
    EXPECT_EQ(factCycle(-1), 0);
}
TEST(Tests, FactorialTestCycle2) {
    EXPECT_EQ(factCycle(0), 1);
}
TEST(Tests, FactorialTestCycle3) {
    EXPECT_EQ(factCycle(1), 1);
}
TEST(Tests, FactorialTestCycle4) {
    EXPECT_EQ(factCycle(2), 2);
}
TEST(Tests, FactorialTestCycle5) {
    EXPECT_EQ(factCycle(5), 120);
}
TEST(Tests, FactorialTestCycle6) {
    EXPECT_EQ(factCycle(10), 3628800);
}
TEST(Tests, FactorialTestCycle7) {
    EXPECT_EQ(factCycle(15), 1307674368000);
}
