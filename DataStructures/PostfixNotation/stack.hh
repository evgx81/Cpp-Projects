#ifndef STACK_H
#define STACK_H

struct Node {
    char data;
    Node *next;
};

typedef Node* TStack;

void init(TStack&);
void print(TStack);
void clear(TStack&);

bool isEmpty(TStack);

int peek(TStack);
void push(TStack&, char);
void pop(TStack&);

#endif