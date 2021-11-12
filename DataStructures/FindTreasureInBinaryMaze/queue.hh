#ifndef QUEUE_H
#define QUEUE_H

#include "cell.hh"

class Queue
{
    struct queueNode
    {
        // Координаты текущей клетки
        Cell m_cell;
        // Расстояние от первоначальной клетки до клада 
        int m_dist;
        // Указатель на следующую вершину
        queueNode* m_next;

        queueNode(Cell cell = 0, int dist = 0) : m_cell{cell}, m_dist{dist}, m_next{nullptr} {}
    };
    queueNode* m_head;
    queueNode* m_tail;
public:
    Queue() : m_head{nullptr}, m_tail{nullptr} {};
    ~Queue();
public:
    bool isEmpty() const;
    void enQueue(Cell, int);
    void deQueue();
    Cell getFrontCell() const;
    int getFrontDistance() const;
    void clear();
};
#endif