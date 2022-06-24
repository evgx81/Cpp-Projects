#ifndef SINGLY_LIST_H
#define SINGLY_LIST_H

#include <iostream>
#include "tree.h"

struct Node {
    TTree data;
    Node* next;
};

typedef Node* TList;

// Инициализация списка
void init(TList&);

// Очистка списка
void clear(TList&);

// Проверка на пустоту
bool isEmpty(TList);

// Добавление в начало спиcка
void addToHead(TList&, TTree&);

// Добавление после pNode
void addAfterNode(TList, int);

// Удаление головы head
void deleteFromHead(TList&);

// Удаление поля pNode
void deleteAfterNode(TList);

// Создание в обратном порядке
void createFromHead(TList&);

// Создание в прямом порядке
void createFromTail(TList&);

// Создание в упорядоченном порядке
void createByOrder(TList&);

TList findPlace(TList, int);

// Печать списка
void printList(TList&);

#endif