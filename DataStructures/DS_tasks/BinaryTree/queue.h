#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

struct QueueNode {
	TTree data;
	QueueNode * next;
};

typedef QueueNode * TQueue;
//typedef TTree TypeData;

TQueue initQueue(TQueue&);
void clearQueue(TQueue&, TQueue&);
void enQueue(TQueue&, TQueue&, TTree);
void deQueue(TQueue&);
void deQueue(TQueue&, TQueue&, TTree&);
bool isEmpty(TQueue);
void getFront(TQueue, TTree&);

#endif