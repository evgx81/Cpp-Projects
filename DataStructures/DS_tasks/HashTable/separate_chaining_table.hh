#ifndef SEPARATE_CHAINING_TABLE
#define SEPARATE_CHAINING_TABLE

#include "hash_table.hh"

class SeparateChainingTable : public HashTable
{
    struct Node
    {
        TKey key;
        TValue value;
        Node* next;    
    };
    // Емкость таблицы
    int capacity; 
    // Текущее число элементов в таблице
    int size;
    // Массив массивов
    Node** cells;
    // Хэш-функция
    int hash(TKey);
public:
    SeparateChainingTable(int);
    SeparateChainingTable(const SeparateChainingTable&);
    ~SeparateChainingTable();
public:
    void insert(TKey, TValue);
    bool remove(TKey);
    bool find(TKey);
    void clear();
    TValue get(TKey);
    bool isEmpty();
    void print();
    int get_size(); 
};

#endif