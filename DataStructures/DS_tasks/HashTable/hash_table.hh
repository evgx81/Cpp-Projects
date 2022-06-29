#ifndef HASH_TABLE
#define HASH_TABLE

#include <iostream>

typedef int TKey;
typedef std::string TValue;


class HashTable
{
public:
    virtual ~HashTable() { }
public:
    virtual void insert(TKey key, TValue value) = 0;
    virtual bool remove(TKey key) = 0;
    virtual bool find(TKey key) = 0;
    virtual void clear() = 0;
    virtual TValue get(TKey key) = 0;
    virtual bool isEmpty() = 0;
    virtual void print() = 0;
};


#endif