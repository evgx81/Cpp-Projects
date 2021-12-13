#include "list.h"

void init(TList &head) {
    head = nullptr;
}

bool isEmpty(TList head) {
    return head == nullptr;
}

void clear(TList &head) {
    while(!isEmpty(head)) {
        deleteFromHead(head);
    }
}

void addToHead(TList &head, int elem) {
    TList p = new Node;
    p->data = elem;
    p->next = head;
    head = p;
}

void addAfterNode(TList pNode, int elem) {
    TList p = new Node;
    p->data = elem;
    p->next = pNode->next;
    pNode->next = p; 
}

void deleteFromHead(TList &head) {
    TList p = head;
    head = head->next;
    p->next = 0;
    delete p;
    p = nullptr;
}

void deleteAfterNode(TList pNode) {
    TList p = pNode->next;
    if(p != nullptr) {
        pNode->next = p->next;
        p->next = nullptr;
        delete p;
        p = nullptr;
    }
}

