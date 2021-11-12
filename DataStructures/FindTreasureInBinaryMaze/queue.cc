#include "queue.hh"

bool Queue::isEmpty() const
{
    return (m_head == nullptr) && (m_tail == nullptr);
}

void Queue::deQueue()
{
    if (isEmpty())
        throw std::underflow_error("The queue is empty!");
    queueNode* p = m_head;
    if(m_head->m_next == nullptr)
       m_tail = nullptr; 
    m_head = m_head->m_next;
    p->m_next = nullptr;
    delete p;
}

void Queue::enQueue(Cell cell, int dist)
{
    queueNode* p = new queueNode;
    p->m_cell = cell;
    p->m_dist = dist;
    p->m_next = nullptr;
    if (m_tail)
    {
        m_tail->m_next = p;
        m_tail = p;
    }
    else 
    {
        m_head = p;
        m_tail = p;
    }
}

Cell Queue::getFrontCell() const
{
    if (isEmpty())
        throw std::underflow_error("The queue is empty!");
    return m_head->m_cell;;
}

int Queue::getFrontDistance() const
{
    if (isEmpty())
        throw std::underflow_error("The queue is empty!");
        
    return m_head->m_dist;
}

void Queue::clear()
{
    while(!isEmpty())
        deQueue();
}

Queue::~Queue()
{
    clear();
}