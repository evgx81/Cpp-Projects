#ifndef LIST_H
#define LIST_H

#include <iostream>

template <typename T>
class List {
    // Узел листа
    struct Node {
        T m_data;
        Node* m_next;
        Node() : m_next{nullptr} {}
    };
    // Указатель на голову списка
    Node* m_head;
    // Указатель на элемент после последнего элемента списка списка
    Node* m_tail; 
public:
    // Конструктор по умолчанию
    List() : m_tail{new Node} { m_head = m_tail; }
    // Деструктор
    ~List()
    {
        while(!isEmpty())
            deleteFromHead();
    }
public:
    // Проверка на пустоту
    bool isEmpty() const
    {
        return m_head == m_tail;
    }
    // Добавление в начало списка
    void addToHead(const T& newElem)
    {
        Node* newNode = new Node;
        newNode->m_data = newElem;
        newNode->m_next = m_head;
        if (isEmpty())
            newNode->m_next = m_tail;
        m_head = newNode;
    }
    // Добавление после заданной вершины
    void addAfterNode(Node* node, const T& newElem)
    {
        Node* newNode = new Node;
        newNode->m_data = newElem;
        newNode->m_next = node->m_next;
        if (newNode->m_next == nullptr)
            newNode->m_next = m_tail;
        node->m_next = newNode;
    }
    // Получаем элемент из головы списка
    T& getHeadValue() const
    {
        if(m_head == nullptr)
            throw std::underflow_error("The list is empty!");
        return m_head->m_data;
    }
    // Удаление головы
    void deleteFromHead()
    {
        Node* p = m_head;
        m_head = m_head->m_next;
        p->m_next = 0;
        delete p;
        p = 0;
    }
    // Удаление после заданной вершины
    void deleteAfterNode(Node* node)
    {
        Node* p = node->m_next;
        if(p != nullptr) {
            node->m_next = p->m_next;
            p->m_next = nullptr;
            delete p;
            p = 0;
            if(node->m_next == nullptr)
                node->m_next = m_tail;
        }
    }
public:
    class iterator
    {
        Node* m_where;
    public:
        iterator(const iterator& other) : m_where(other.m_where) {}
        iterator(Node* where = nullptr) : m_where(where) {}

        const iterator& operator=(const iterator& other) {
            m_where = other.m_where;
        }

        bool operator==(const iterator& other) const
        {
            return m_where == other.m_where; 
        }

        bool operator!=(const iterator& other) const
        {
            return m_where != other.m_where;
        }

        const iterator& operator++() { //prefix increment
            if (m_where->m_next == nullptr)
                throw std::range_error("bad pointer");
            else
                m_where = m_where->m_next;
            return *this;
        }

        iterator operator++(int) { // postfix increment
            iterator result = *this;
            ++(*this);
            return result;
        }

        T& operator*() {
            if(m_where->m_next == nullptr)
                throw std::range_error("bad_pointer");
            return m_where->m_data;
        }

        T* operator->() {
            return &(m_where->m_data);
        }
    };

    iterator begin() const { return iterator(m_head); }
    iterator end() const { return iterator(m_tail); }
  
};


#endif