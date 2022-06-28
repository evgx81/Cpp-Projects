#include "circle.hh"

#include <iostream>

TList init(int data) 
{
    TList node = new Node;
    node->data = data;
    node->next = node;
    return node;
}

void deleteAfterNode(TList& head, TList pNode)
{
    if(pNode->next == head)
        head = head->next;
    TList p = pNode->next;
    pNode->next = p->next;
    p->next = 0;
    delete p;
    p = 0;
}

void addAfterNode(TList pNode, int elem) {
    TList p = new Node;
    p->data = elem;
    p->next = pNode->next;
    pNode->next = p; 
}

void print(TList head)
{
    TList p = head;
    while(p->next != head)
    {
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << p->data << '\n';
}