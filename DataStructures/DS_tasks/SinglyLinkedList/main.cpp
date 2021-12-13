#include "list.h"
#include <iostream>

// Печать элементов списка
void printList(TList head) {
    TList p = head;
    while(p != nullptr) {
        std::cout << p->data << " ";
        p = p -> next;
    }
    std::cout << '\n';
}

// Создание списка в прямом порядке
void createFromHead(TList &head) {
    init(head);
    for(int i = 0; i < 5; i++)
        addToHead(head, i);
}

// Создание списка в прямом порядке
void createFromTail(TList &head) {
    init(head);
    TList tail;
    for(int i = 0; i < 5; i++) {
        if(isEmpty(head)) {
            addToHead(head, i);
            tail = head;
        }
        else {
            addAfterNode(tail, i);
            tail = tail -> next;
        }
    } 
}

// Нахождение нуля в списке
TList findFirstZero(TList pNode) {
    TList p = pNode;
    while(p != 0 && p->data != 0)
        p = p->next;
    return p;
}

// Печатаем элементы между 2-мя нулями
void print(TList pFirstZero, TList pSecondZero) {
    while(pFirstZero != pSecondZero) {
        std::cout << pFirstZero->data << ' ';
        pFirstZero = pFirstZero->next;
    }
    std::cout << pSecondZero->data << '\n';
}

// Вывод эл-в списка, расп. между первым и вторым нулевыми элементами, включая нули 
void printBetweenTwoFirstZeros(TList head) {
    TList pFirstZero = findFirstZero(head);
    if(pFirstZero == nullptr)
        std::cout << "Нет нулей в списке" << '\n';
    else {
        //Находим 2-й нуль
        TList pSecondZero = findFirstZero(pFirstZero->next);
        if (pSecondZero == nullptr)
            std::cout << "Только 1 нуль" << '\n';
        else
            print(pFirstZero, pSecondZero);
    }
        
}

// Нахожение адреса перед нечетным элементов
TList findOddElement(TList head) {
    TList p = head;
    while(p != 0 && std::abs(p->next->data) % 2 == 0)
        p = p->next;
    return p;
}


// Удаление из списка первую группу подряд идущих нечетных элементов
void deleteFirstOddGroup(TList &head) {
    TList p = head;
    if(head != nullptr && std::abs(head->data % 2) != 0) {
        while(head != nullptr && std::abs(head->data) % 2 != 0)
            deleteFromHead(head);
    }
    else {
        TList p = findOddElement(head);
        if(p != nullptr) {
            deleteAfterNode(p);
            while(p != nullptr && std::abs(p->data)%2 != 0)
                deleteAfterNode(p);
        }
    }

}

// Удаление организовывать только через узнавание адреса предыдущего элемента
// Нахождение предыдущего четного элемента, после него удаляем все нечетные элементы

//  Нахождение адреса перед отрицательным элементом
TList findNegativeElement(TList pNode) {
    TList p = pNode;
    while(p->next != 0 && p->next->data >= 0)
        p = p->next;
    return p;
}

// Удаление всех отрицательных чисел
void deleteAllNegativeNumbers(TList &head) {
    if(head != nullptr && head->data <= 0) {
        while(head != nullptr && head->data <= 0)
            deleteFromHead(head);
    }
    TList p = head;
    std::cout << p->data << '\n';
    while(p != nullptr) {
        TList pNeg = findNegativeElement(p);
        std::cout << pNeg->data << '\n';
        if(pNeg != nullptr)
            deleteAfterNode(pNeg);
        std::cout << pNeg->data << '\n';
        p = p->next;
    }

}

// Поменять местами первый и последний элементы списка путем перестановки ссылок
void changeFirstLastElementsByChangeReference(TList& head) {
    TList tail = head;
    TList p1 = head;
    TList p = head;

    if(head->next == nullptr) {
        std::cout << "В списке один элемент";
    }
    else {
    while(tail->next->next != 0){
        tail = tail->next;
    }
    // теперь tail стоит на предпоследнем элементе
        if (tail == head) {
            tail->next->next = head;
            head = tail->next;
            p1->next = nullptr;
        }
        else {
            tail->next->next = head->next;
            p = tail->next;
            head = p;
            tail->next = p1;
            p1->next = 0;
        }
    }


}

// Поменять местами минимальный и максимальный элементы списка.
// Гарантируется, что максимальный и минимальный элементы единственные

// Находим максимальный элемент
TList findMaxElem(TList& head) {
    TList p = head;
    TList pMax = nullptr;
    int max = p->data;
    while(p != 0) {
        if(p->data > max) {
            max = p->data;
            pMax = p;
        }
            
        p = p->next;
    }
    return pMax;
}

// Находим минимальный элемент
TList findMinElem(TList& head) {
    TList p = head;
    TList pMin = head;
    int min = p->data;
    while(p != 0) {
        if(p->data < min) {
            min = p->data;
            pMin = p;
        }
            
        p = p->next;
    }
    return pMin;
}

// Меняем максимальный и минимальный элементы местами
void exchangeMaxAndMin(TList head) {

    int temp{0};
    TList max = findMaxElem(head);
    TList min = findMinElem(head);

    if(min == nullptr)
        std::cout << "Минимального элемента не существует " << '\n';
    else if (min == nullptr)
        std::cout << "Максимального элемента не существует " << '\n';
    else {
        temp = min->data;
        min->data = max->data;
        max->data = temp;
    }
    
}

// Удалить из списка М за каждым вхождением элемента Е один элемент, если такой есть и он отличен от Е.
void deleteAfterE(TList M, int E) {

    TList p = M;
    while(p != 0) {
        if(p->data == E && p->next->data != E)
            deleteAfterNode(p);
        p = p->next;
    }
}

// Находим адрес элемента перед максимальным элементом
TList findMaxAdress(TList& head) 
{
    TList p = head;
    TList pmax = 0;
    int max = head->data;
    while(p->next != 0) {
        if (p->next->data > max) {
            max = p->next->data;
            pmax = p;
        }
        p = p->next;
    }
    return pmax;
}

// Находим адрес элемента перед минимальным элементом
TList findMinAdress(TList& head) 
{
    TList p = head;
    TList pmin = 0;
    int min = head->data;
    while(p->next != 0) {
        if (p->next->data < min) {
            min = p->next->data;
            pmin = p;
        }
        p = p->next;
    }
    return pmin;
}

int findIndex(TList head, TList elem) 
{
    int index = 0;
    if(elem == nullptr) 
        index = -1;
    else {
        TList p = head;
        bool flag = false;
        while(p != 0 && flag == false) {
            index++;
            if(p == elem) 
                flag = true;
            p = p->next;
        }
    }
    return index;
}

void checkIndex(TList& head, TList& p1, TList& p2) 
{
    int p1Index = findIndex(head, p1);
    int p2Index = findIndex(head, p2);

    if(p1Index > p2Index) {
        TList tmp = p1;
        p1 = p2;
        p2 = tmp;
    }
}

void swap(TList& head, TList& p1, TList& p2) {
    if (p1 != 0) 
    {
        TList subhead = p1->next;
        TList subtail = p2->next;

        if(p2->next->next != 0) 
        {
            TList tail = subtail->next;
            p1->next = 0;
            subtail->next = 0;
            changeFirstLastElementsByChangeReference(subhead);
            p1->next = subtail;
            subhead->next = tail;
        }
        else 
        {
            p1->next = 0;
            changeFirstLastElementsByChangeReference(subhead);
            p1->next = subtail;
        }
    }
    else
    {
        if (p2->next->next != 0) {
            TList subtail = p2->next;
            TList tail = p2->next->next;
            subtail->next = 0;
            changeFirstLastElementsByChangeReference(head);
            p2->next->next = tail;
        }
        else 
            changeFirstLastElementsByChangeReference(head);
    } 
}


void swapMaxAndMin(TList& head) 
{
    TList p1 = findMinAdress(head);
    TList p2 = findMaxAdress(head);

    checkIndex(head, p1, p2);

    swap(head, p1, p2);
}

void reverse(TList& head) 
{
    TList p = head;
    TList prev = nullptr;
    TList next = nullptr;
 
    while (p != 0) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    head = prev;
}

TList findFirstElemAdress(TList& pNode, int elem) 
{
    TList p1 = pNode;
    if(pNode->data == elem) 
    {
        p1 = nullptr;
    }
    else 
    {
        while(p1->next != 0 && p1->next->data != elem) {
            p1 = p1->next; 
        }
    }
    
    return p1;
}

void changeSubtail(TList& subtail) {
    while (subtail->next != 0)
        subtail = subtail->next;
    
}

TList findSecondElemAdress(TList& head, int elem) 
{
    TList p = head;
    TList p2 = nullptr;
    while(p->next != 0)
    {
        if(p->next->data == elem)
            p2 = p;
        p = p->next;
    }
    return p2;
}

void reverseBetweenTwoNodes(TList& head, int elem) 
{
    // Элемент перед первым L
    TList p1 = findFirstElemAdress(head, elem);
    if(p1 == nullptr) 
    {
        TList p2 = findSecondElemAdress(head->next, elem);

        if (p2 != 0) {
            

            TList subhead = head;
            TList subtail = p2->next;
            TList tail = subtail->next;
            if (tail == nullptr) {
                reverse(subhead);
                head = subhead;
            }
            else 
            {
                subtail->next = 0;
                reverse(subhead);
                changeSubtail(subtail);
                subtail->next = tail;
                head = subhead;
            }
        }
    }
    else 
    {
        TList p2 = findSecondElemAdress(p1->next->next, elem);
        if (p2 != 0) {
            TList subhead = p1->next;
            TList subtail = p2->next;

            TList p = head;
            while(p != p1)
                p = p->next;

            p->next = 0;

            TList tail = subtail->next;

            if (tail == nullptr) {
                reverse(subhead);
                p->next = subhead;
            }
            else 
            {
                subtail->next = 0;
                reverse(subhead);
                changeSubtail(subtail);
                p->next = subhead;
                subtail->next = tail;
            }
        }
    }
}

TList findPlace(TList pNode, int elem) 
{
    TList p = pNode;
    while(p->next != 0 && p->next->data != elem)
        p = p->next;
    return p;
}

TList uniteLists(TList& head1, TList& head2, TList& head3)
{
    TList p1 = head1;
    TList p2 = head2;

    TList min1 = findMinElem(head1);
    TList min2 = findMinElem(head2);

    TList p = head3;

    while (p1 != 0 && p2 != 0)
    {
        min1 = findMinElem(p1);
        min2 = findMinElem(p2);

         if (min1->data <= min2->data){
            addToHead(head3, min1->data);
            addToHead(head3, min2->data);
        }
        else{
            addToHead(head3, min2->data);
            addToHead(head3, min1->data);
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    reverse(head3);
    return head3;
}

int main() {
    TList head1;
    init(head1);
    
    TList head2;
    init(head2);

    // addToHead(head1, 1);
    // addToHead(head1, 0);
    // addToHead(head1, 3);
    // addToHead(head1, 2);
    // addToHead(head1, 4);
    // addToHead(head1, 3);
    // addToHead(head1, 1);
    // addToHead(head1, 2);

    // printList(head1);

    // TList p1 = findMinAdress(head1);
    // TList p2 = findMaxAdress(head1);

    addToHead(head1, 5);
    addToHead(head1, 4);
    addToHead(head1, 3);
    addToHead(head1, 2);
    addToHead(head1, 1);

    addToHead(head2, 7);
    addToHead(head2, 6);
    addToHead(head2, 5);
    addToHead(head2, 3);
    addToHead(head2, 2);

    // printList(head1);
    // printList(head2);

    // while(p->next != 0)
    //     p = p->next;
    // std::cout << p->data <<  '\n'; // указатель на последнем элементе

    // TList m = findMinElem(head1);

    // std::cout << m->data <<  '\n'; // указатель на последнем элементе

    // exchangeMaxAndMin(head1);

    // changeFirstLastElementsByChangeReference(head1);

    // deleteAfterE(head1, 20);

    // deleteAfterNode(head1);

    // int index = findIndex(head1, p2);

    // swapMaxAndMin(head1);

    // reverse(head1);

    // TList elem = findElemAdress(head1, 2);

    // TList elem1 = findElemAdress(elem->next, 2);

    // reverseBetweenTwoNodes(head1, 2);

    TList head3;
    init(head3);

    head3 = uniteLists(head1, head2, head3);

    printList(head1);

    
    return 0;
}

