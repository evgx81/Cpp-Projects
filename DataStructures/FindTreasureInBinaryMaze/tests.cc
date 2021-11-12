#include <gtest/gtest.h>
#include <sstream>
#include <iostream>

#include "matrix.hh"
#include "cell.hh"
#include "queue.hh"

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

TEST(MatrixTests, createEmptyMatrix)
{
    Matrix<int> matr = Matrix<int>(3);
    std::stringstream ss;
    ss << matr;
    std::string s = ss.str();
    EXPECT_EQ(s, "0 0 0 \n0 0 0 \n0 0 0 \n");
}

TEST(MatrixTests, createEmptyMatrixWithVal)
{
    Matrix<int> matr = Matrix<int>(3, 1);
    std::stringstream ss;
    ss << matr;
    std::string s = ss.str();
    EXPECT_EQ(s, "1 1 1 \n1 1 1 \n1 1 1 \n");
}

TEST(MatrixTests, copyMatrix)
{
    Matrix<int> matr1 = Matrix<int>(2, 1);
    Matrix<int> matr2 = matr1; 
    std::stringstream ss1;
    ss1 << matr2;
    std::string s = ss1.str();
    EXPECT_EQ(s, "1 1 \n1 1 \n");
}

TEST(MatrixTests, returnValueOfMatrix)
{
    Matrix<int> matr = Matrix<int>(2);
    std::string data = "1 2 3 4";
    std::stringstream ss(data);
    ss >> matr;
    Cell pos = Cell(0, 1);
    int val = matr[pos];
    EXPECT_EQ(val, 2);
}

TEST(MatrixTests, readMatrix)
{
    Matrix<int> matr = Matrix<int>(2);
    std::string data = "1 2 3 4";
    std::stringstream ss(data);
    ss >> matr;
    std::stringstream ss1;
    ss1 << matr;
    std::string s = ss1.str();
    EXPECT_EQ(s, "1 2 \n3 4 \n");
}

TEST(QueueTests, isEmptyEmptyQueue)
{
    Queue queue;
    bool flag = queue.isEmpty();
    EXPECT_EQ(flag, true);
}
TEST(QueueTests, isEmptyNotEmptyQueue)
{
    Queue queue;
    Cell cell = (2, 3);
    int s = 3;
    queue.enQueue(cell, s);
    bool flag = queue.isEmpty();
    EXPECT_EQ(flag, false);
}

TEST(QueueTests, isEmpty)
{
    Queue queue;
    queue.enQueue((4,4), 1);
    queue.enQueue((5,5), 5);
    queue.deQueue();
    queue.deQueue();

    bool flag = queue.isEmpty();
    EXPECT_EQ(flag, true);
}

TEST(QueueTests, enQueueWithCell)
{
    Queue queue;
    queue.enQueue((4,4), 0);
    bool flag = queue.getFrontCell() == (4, 4);
    EXPECT_EQ(flag, true);
}

TEST(QueueTests, enQueueWithDistance)
{
    Queue queue;
    queue.enQueue((0,0), 3);
    bool flag = queue.getFrontDistance() == 3;
    EXPECT_EQ(flag, true);
}

TEST(QueueTests, deQueueWithCell)
{
    Queue queue;
    queue.enQueue((3,3), 3);
    queue.enQueue((4, 4), 4);
    queue.deQueue();
    bool flag = queue.getFrontCell() == (4, 4);
    EXPECT_EQ(flag, true);
}

TEST(QueueTests, deQueueWithDistance)
{
    Queue queue;
    queue.enQueue((3,3), 5);
    queue.enQueue((4, 4), 10);
    queue.deQueue();
    bool flag = queue.getFrontDistance() == 10;
    EXPECT_EQ(flag, true);
}

