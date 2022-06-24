#include "singly_list.h"

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

void addToHead(TList &head, TTree& elem) {
    TList p = new Node;
    p->data = elem;
    p->next = head;
    head = p;
}

// void addAfterNode(TList pNode, int elem) {
//     TList p = new Node;
//     p->data = elem;
//     p->next = pNode->next;
//     pNode->next = p; 
// }

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

// Печать элементов списка
void printList(TList& head) {
    TList p = head;
    while(p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << '\n';
}

// // Создание списка в прямом порядке
// void createFromHead(TList &head) {
//     init(head);
//     for(int i = 0; i < 5; i++)
//         addToHead(head, i);
// }

// // Создание списка в прямом порядке
// void createFromTail(TList &head) {
//     init(head);
//     TList tail;
//     for(int i = 0; i < 5; i++) {
//         if(isEmpty(head)) {
//             addToHead(head, i);
//             tail = head;
//         }
//         else {
//             addAfterNode(tail, i);
//             tail = tail -> next;
//         }
//     } 
// }
// void createByOrder(TList& head)
// {
// 	init(head);
// 	for (int i = 0; i < 5; i++) {
//         int elem = rand() % 10;
//         if (isEmpty(head) || elem <= head->data) addToHead(head, elem);
//         else
//         {
//             TList p = findPlace(head, i);
// 		    addAfterNode(p, elem);
//         }
		
// 	}
// }

// TList findPlace(TList pNode, int elem)
// {
//     TList p = pNode;
//     while (p->next != 0 && p->next->data < elem)
//         p = p->next;
//     return p;
// }

