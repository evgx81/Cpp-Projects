#include "stack.hh"

#include <iostream>

// Инициализация списка
void init(TStack &top) {
    top = nullptr;
}

// Проверка на пустоту
bool isEmpty(TStack top) {
    return top == nullptr;
}

// Получаем первый элемент
int peek(TStack top) {
    return top->data;
}

void print(TStack top) {
    TStack p = top;
    while(p != nullptr) {
        std::cout << p->data << "\n";
        p = p->next;
    }
}

// Очистка стека
void clear(TStack &top) {
    while(!isEmpty(top))
        pop(top);
}

// Добавление элемента в голову списка
void push(TStack &top, char value) {
    TStack p = new Node;
    p->data = value;
    p->next = top;
    top = p;
}

// Удаление элемента из головы
void pop(TStack &top) {
    TStack p = top;
    top = top->next;
    p->next = nullptr;
    delete p;
    p = nullptr;
}