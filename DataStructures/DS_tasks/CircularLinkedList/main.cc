#include "circle.hh"

#include <iostream>

// Удвоить каждое вхождение элемента E
void doubleE(TList& head, int E) 
{
   TList p = head;
   while(p->next != head)
    {   if(p->data == E)
        {
            addAfterNode(p, E);
            p = p->next;
        } 
        p = p->next;
    }
    if(p->data == E)
        addAfterNode(p, E);
}

// Подсчитать кол-во элементов, у кот. равные соседи
int countNeighbours(TList head)
{
    TList p = head;
    int count = 0;
    while(p->next != head)
    {
        if(p->data == p->next->data)
            count++;
        p = p->next;
    }
    if (p->data == head->data)
        count++;
    return count;
}

// Из списка, сод. не менее 3 элементов, удалить все элементы, у кот. одинаковые соседи
void deleteNeighbours(TList& head)
{
    TList p = head;
    TList next = p->next;
    while(p->next != head)
    {
        if(p->data = next->next->data)
        {
            if(next->data == next->next->next->data) 
                deleteAfterNode(head, p);
            
            deleteAfterNode(head, p);
        }
        print(head);
        p = next;
        next = next->next;
    }
    if (p->data == head->data)
        deleteAfterNode(head, p->next);
    if(head == nullptr)
        std::cout << "Пустой список!";
    
}

int main()
{
    TList head = init(1);
    addAfterNode(head, 2);
    addAfterNode(head, 3);
    addAfterNode(head, 4);
    addAfterNode(head, 2);
    print(head);
    doubleE(head, 2); 
    print(head); 
    return 0;
}