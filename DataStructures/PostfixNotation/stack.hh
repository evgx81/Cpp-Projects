#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
    // Узел стека
    struct Node {
        T m_data;
        Node* m_next;

        Node() : m_next{nullptr} {}
    };
    // Указатель на верхушку стека
    Node* m_top;
public:
    // Инициализация списка
    Stack() : m_top{nullptr} {}
    ~Stack()
    {
        clear();
    }
public:
    // Проверка на пустоту
    bool isEmpty()
    {
        return m_top == nullptr;
    }
    // Получаем верхний элемент
    T& peek()
    {
        return m_top->m_data;
    }
    // Добавление элемента в голову списка
    void push(const T& elem) {
        Node* p = new Node;
        p->m_data = elem;
        p->m_next = m_top;
        m_top = p;
    }
    // Удаление элемента из головы
    void pop() 
    {
        Node* p = m_top;
        m_top = m_top->m_next;
        p->m_next = nullptr;
        delete p;
        p = nullptr;
    }
    // Очистка стека
    void clear() 
    {
        while(!isEmpty())
            pop();
    }
};


#endif