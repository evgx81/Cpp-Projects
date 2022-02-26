#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>
#include "car.hh"

typedef StateNumber TKey;
typedef Car TValue;

class HashTable
{
public:
    // Виртуальный деструктор
    virtual ~HashTable() {}
public:
    // Вставка элемента
    virtual void insert(TKey, TValue) = 0;
    // Удаление элемента
    virtual bool remove(TKey) = 0;
    // Получение значения элемента по ключу
    virtual TValue get(TKey) = 0;
    // Печать таблицы
    virtual void print() = 0;
    // Очистка таблицы
    virtual void clear() = 0;
public:
    // Проверка пуста ли таблица
    virtual bool isEmpty() = 0;
    // Проверка находится ли элемент в таблице
    virtual bool find(TKey) = 0;
    // Определение размера таблицы
    virtual int size() = 0; 
};

#endif