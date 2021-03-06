#ifndef QUADRATIC_PROBING_TABLE
#define QUADRATIC_PROBING_TABLE

#include "hash_table.hh"
#include <stdexcept>


enum Status
{
    REMOVED = -1, // Элемент удален
    EMPTY,        // Ячейка свободна
    FILLED        // Ячейка заполнена
};

struct HashItem
{
    TValue m_value;
    TKey m_key;
    Status m_status;
public:
    HashItem() : m_value{}, m_key{}, m_status{EMPTY} {}
    ~HashItem(){}
public:
    HashItem(const HashItem& hash_item)
    {
        m_value = hash_item.m_value;
        m_key = hash_item.m_key;
        m_status = hash_item.m_status;
    }
    HashItem& operator=(const HashItem& hash_item) {
        m_value = hash_item.m_value;
        m_key = hash_item.m_key;
        m_status = hash_item.m_status;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const HashItem& hash_item)
    {
        os << hash_item.m_value << ' ';
        return os;
    }
};

class QuadraticProbingTable : public HashTable
{
    HashItem* m_table;
    // Емкость таблицы
    int m_capacity;
    // Текущее число элементов в таблице
    int m_size;
private:
    // Хеш-функция
    int hash(TKey);
    // Квадратичное опробирование
    int quadratic_probing(int);
    // Проверка существует ли элемент с данным ключом в таблице с помощью квадратичного пробирования
    bool is_elem_in_table_with_quadratic_probing(int, TKey);
    // Поиск индекса, на котором находится элемент с помощью квадратичного пробирования
    int find_index_elem_with_quadratic_probing(int, TKey);
private:
    // Функция, которая будет увеличивать размер таблицы при заполненности хэш-таблицы выше 75% 
    bool isFull() {return m_size >= m_capacity * 0.75;}
    // Автоматическое увеличение размерности хэш-таблицы в 2 раза
    void rehashing();
public:
    QuadraticProbingTable(int);
    QuadraticProbingTable(const QuadraticProbingTable&);
    ~QuadraticProbingTable();
public:
    void insert(TKey, TValue);
    bool remove(TKey);
    TValue get(TKey);
    void print();
    void clear();
public:
    bool isEmpty();
    bool find(TKey);
    int size(); 

}; 
#endif

