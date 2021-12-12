#ifndef STACK_H
#define STACK_H

#include "tree.h"

struct StackNode {
	TTree data;
	StackNode * next;
};

typedef StackNode * TStack;

void initStack(TStack&);
bool isEmpty(TStack);
void push(TStack&, TTree);
void pop(TStack&);
void pop(TStack&, TTree&);
void clearStack(TStack&);

#endif