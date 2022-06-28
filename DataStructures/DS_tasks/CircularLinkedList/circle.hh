#ifndef CIRCLE_H
#define CIRCLE_H

struct Node {
    int data;
    Node* next;
};

typedef Node* TList;

// Инициализация списка
TList init(int);

// Добавление после pNode
void addAfterNode(TList pNode, int elem);

// Добавление после pNode
void deleteAfterNode(TList&, TList);

// Печать списка
void print(TList);

#endif