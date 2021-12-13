#ifndef LIST_H
#define LIST_H

struct Node {
    int data;
    Node* next;
};

typedef Node* TList;

// Инициализация списка
void init(TList&);

// Очистка списка
void clear(TList);

// Проверка на пустоту
bool isEmpty(TList);

// Добавление в начало спика
void addToHead(TList&, int);

// Добавление после pNode
void addAfterNode(TList, int);

// Удалениее головы head
void deleteFromHead(TList&);

// Удаление поля pNode
void deleteAfterNode(TList);

#endif