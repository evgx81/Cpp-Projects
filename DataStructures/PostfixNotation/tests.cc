#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "stack.hh"
#include "tree.hh"

TEST(StackTests, isEmptyStack)
{
    Stack<int> stack = Stack<int>();
    bool flag = stack.isEmpty();
    EXPECT_EQ(flag, true);
}
TEST(StackTests, isEmptyNotEmptyStack)
{
    Stack<int> stack = Stack<int>();
    stack.push(3);
    bool flag = stack.isEmpty();
    EXPECT_EQ(flag, false);
}

TEST(StackTests, isEmpty)
{
    Stack<int> stack = Stack<int>();
    stack.push(3);
    stack.push(4);
    stack.pop();
    stack.pop();
    bool flag = stack.isEmpty();
    EXPECT_EQ(flag, true);
}

TEST(StackTests, peek)
{
    Stack<int> stack = Stack<int>();
    stack.push(3);
    int i = stack.peek();
    EXPECT_EQ(i, 3);
}

TEST(StackTests, push)
{
    Stack<int> stack = Stack<int>();
    stack.push(3);
    stack.push(4);
    stack.push(5);
    int i = stack.peek();
    EXPECT_EQ(i, 5);
}

TEST(StackTests, pop)
{
    Stack<int> stack = Stack<int>();
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.pop();
    int i = stack.peek();
    EXPECT_EQ(i, 4);
}

TEST(StackTests, clear)
{
    Stack<int> stack = Stack<int>();
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.clear();
    bool flag = stack.isEmpty();
    EXPECT_EQ(flag, true);
}

