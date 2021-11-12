#include "List.hh"
#include "longNumbersFunctions.hh"

#include <iostream>
#include <sstream>

void readNumberFromFile(TList& number, const std::string num, bool& sign) {
    // Строковый поток, чтобы считывать каждую цифру длинного числа
    std::stringstream ss(num);
    char ch;
    while(ss >> ch) {
        if (ch == '-')
            sign = false;
        else {
            int digit = ch - '0';
            addToHead(number, digit);
        }  
    }
}

int sizeNumber(TList head) {
    TList p = head;
    int num = 0;
    while(p != 0) {
        num++;
        p = p->next;
    }
    return num;
}

void sumLastDigits(TList& num, TList& sum, int v_ume, int digit, int minCount) {
    int digitSum = 0;

    while (num != 0) {
        digit++;

        if(v_ume >= 1) {
            digitSum = num->data + v_ume;
            v_ume = 0;
        }
        else {
            digitSum = num->data;
        }

        if (digitSum >= 10) {
            if (digit < sizeNumber(num) - minCount) {
                digitSum = digitSum - 10;
                v_ume = 1;
            }
        }

        addToHead(sum, digitSum);

        num = num->next;

    }
}


int minCount(TList num1, TList num2) {
    // Переменная будет хранить минимальное число разрядов из 2-x чисел
    int minCount = 0;

    int countNum1 = sizeNumber(num1);
    int countNum2 = sizeNumber(num2);

    if (countNum1 < countNum2)
        minCount = countNum1;
    else
        minCount = countNum2;

    return minCount;
}

TList sum(TList num1, TList num2) {

    // Инициализируем список, который будет хранить сумму 2 чисел
    TList sum;
    init(sum);

    // Счетчики, которые будут бежать по цифрам каждого из чисел
    TList pNum1 = num1;
    TList pNum2 = num2;
    
    // Переменная будет хранить сумму элементов 2-х списков
    int digitSum{0};

    // В уме будем запоминать 1, если сумма чисел больше 1
    int v_ume{0};

    int min_count = minCount(num1, num2);

    // Переменная будет запоминать, на каком мы разряде
    int digit{0};


    while(pNum1 != 0 && pNum2 != 0) {
        // Переходим к следующему разряду
        digit++;

        // Запоминаем в уме десяток
        if(v_ume == 1) {
            digitSum = pNum1->data + pNum2->data + v_ume;
            v_ume = 0;
        }
        else {
            digitSum = pNum1->data + pNum2->data;
        }



        if (digitSum >= 10) {
            if (sizeNumber(num1) == sizeNumber(num2)) {
                if (digit < min_count) {
                    digitSum = digitSum - 10;
                    v_ume = 1;
                }
            }
            else {
                if (digit <= min_count) {
                    digitSum = digitSum - 10;
                    v_ume = 1;
                }
            }
            
        }

        addToHead(sum, digitSum);

        pNum1 = pNum1->next;
        pNum2 = pNum2->next;

    }

    if (pNum1 != nullptr)
        sumLastDigits(pNum1, sum, v_ume, digit, min_count);

    if (pNum2 != nullptr)
        sumLastDigits(pNum2, sum, v_ume, digit, min_count);

    return sum;
}

void subNormalize(TList& head) {
    bool flag = false;
    while(head != nullptr && flag == false) {
        if (head->data == 0)
            deleteFromHead(head);
        else 
            flag = true;
    } 
    if(isEmpty(head))
        addToHead(head, 0);

    
}

bool compareNumbersForSub(TList firstNum, TList secondNum) {
    // Предположим что 2 числа изначально равны
    bool equal = true;
    // Предположим, что первое число больше
    bool isFirstBigger = true;

    TList num1;
    init(num1);

    TList(num2);
    init(num2);

    TList f = firstNum;
    TList s = secondNum;

    // Просто положим цифры в другие спики где addTohead где они уже будут в правильном порядке
    while(f != 0 && s != 0) {

        addToHead(num1, f->data);
        addToHead(num2, s->data);

        f = f->next;
        s = s->next;
    }

    TList pNum1 = num1;
    TList pNum2 = num2;

    while(pNum1 != 0 && pNum2 != 0 && equal == true) {
        if (pNum1->data > pNum2->data) {
            isFirstBigger = true;
            equal = false;
        }
        else if (pNum1->data < pNum2->data) {
            isFirstBigger = false;
            equal = false;
        }

        pNum1 = pNum1->next;
        pNum2 = pNum2->next; 
    }
    return isFirstBigger;
}

void subLastDigits(TList& num, TList& sub, int v_ume) {
    int digitSub = 0;

    while (num != 0) {
        if(v_ume == 1) {
            digitSub = num->data - v_ume;
            v_ume = 0;
        }
        else {
            digitSub = num->data;
        }

        if (digitSub < 0) {
                digitSub += 10;
                v_ume = 1;
        }

        addToHead(sub, digitSub);

        num = num->next;
    }

    
}

TList sub(TList num1, TList num2) {
    // Инициализируем список, который будет хранить сумму 2 чисел
    TList sub;
    init(sub);

    // Счетчики, которые будут бежать по цифрам каждого из чисел
    TList pNum1 = num1;
    TList pNum2 = num2;
    
    // Переменная будет хранить разность элементов 2-х списков
    int digitSub{0};

    // В уме будем запоминать 1, если сумма чисел больше 1
    int v_ume{0};

    int min_count = minCount(num1, num2);

    int loan{0};

    while(pNum1 != 0 && pNum2 != 0) {

        // Запоминаем в уме десяток
        if(v_ume == 1) {
            digitSub = (pNum1->data - v_ume) - pNum2->data;
            v_ume = 0;
        }
        else {
            digitSub = pNum1->data - pNum2->data;
        }

        if (digitSub < 0) {

            if(pNum1->data < pNum2->data || ((pNum1->data == pNum2->data && v_ume == 0))) {
                digitSub += 10;
                v_ume = 1;
        
            }
        }

        addToHead(sub, digitSub);

        pNum1 = pNum1->next;
        pNum2 = pNum2->next;

    }

    if (pNum1 != nullptr)
        subLastDigits(pNum1, sub, v_ume);

    subNormalize(sub);

    return sub;
}

void print(TList result, bool sign) {
    TList p = result;
    if(sign == true)
        std::cout << '-';
    while(p != 0) {
        std::cout << p->data;
        p = p->next;
    }
    std::cout << '\n';
}

void printSum(TList m_firstNumber, TList m_secondNumber, bool f_sign, bool s_sign) {
    TList Sum;
    init(Sum);

    bool negResult;
    // Если оба числа отрицательны
    if(f_sign == false && s_sign == false) {
        negResult = true;
        Sum = sum(m_firstNumber, m_secondNumber);
        print(Sum, negResult);

    } 
    // Если первое число положительно, а второе  отрицательно
    else if (f_sign == true && s_sign == false) {
        if (sizeNumber(m_firstNumber) > sizeNumber(m_secondNumber)) {
            negResult = false;
            Sum = sub(m_firstNumber, m_secondNumber);
            print(Sum, negResult);
            
        }
        else if (sizeNumber(m_firstNumber) < sizeNumber(m_secondNumber)) {
            negResult = true;
            Sum = sub(m_secondNumber, m_firstNumber);
            print(Sum, negResult);
            
        }
        else if (sizeNumber(m_firstNumber) == sizeNumber(m_secondNumber)) {
            bool firstBigger = compareNumbersForSub(m_firstNumber, m_secondNumber);
            if(firstBigger == true){
                negResult = false;
                Sum = sub(m_firstNumber, m_secondNumber);
                print(Sum, negResult);
            }
            else {
                negResult = true;
                Sum = sub(m_secondNumber, m_firstNumber);
                print(Sum, negResult);
            }
           
        }

    }
    // Если первое число отрицательно, а второе положительно
    else if (f_sign == false && s_sign == true) {
        if (sizeNumber(m_firstNumber) > sizeNumber(m_secondNumber)) {
            negResult = true;
            Sum = sub(m_firstNumber, m_secondNumber);
            print(Sum, negResult);
            
        }
        else if (sizeNumber(m_firstNumber) < sizeNumber(m_secondNumber)) {
            negResult = false;
            Sum = sub(m_secondNumber, m_firstNumber);
            print(Sum, negResult);
            
        }
        else if (sizeNumber(m_firstNumber) == sizeNumber(m_secondNumber)) {
            bool firstBigger = compareNumbersForSub(m_firstNumber, m_secondNumber);
            if(firstBigger == true){
                negResult = true;
                Sum = sub(m_firstNumber, m_secondNumber);

                if(Sum->data == 0)
                    negResult = false;
                else 
                    negResult = true;
                
                print(Sum, negResult);
            }
            else {
                negResult = false;
                Sum = sub(m_secondNumber, m_firstNumber);
                print(Sum, negResult);
            }
           
        }
    } 
    // Если оба числа положительны  
    else {
        negResult = false;
        Sum = sum(m_firstNumber, m_secondNumber);
        print(Sum, negResult);
    }
}

void printSub(TList m_firstNumber, TList m_secondNumber, bool f_sign, bool s_sign) {
    TList Sub;
    init(Sub);

    bool negResult;
    // Если оба числа отрицательны
    if(f_sign == false && s_sign == false) {
        if (sizeNumber(m_firstNumber) > sizeNumber(m_secondNumber)) {
            negResult = true;
            Sub = sub(m_firstNumber, m_secondNumber);
            print(Sub, negResult);
            
        }
        else if (sizeNumber(m_firstNumber) < sizeNumber(m_secondNumber)) {
            negResult = false;
            Sub = sub(m_secondNumber, m_firstNumber);
            print(Sub, negResult);
            
        }
        else if (sizeNumber(m_firstNumber) == sizeNumber(m_secondNumber)) {
            bool firstBigger = compareNumbersForSub(m_firstNumber, m_secondNumber);
            if(firstBigger == true){
                negResult = false;
                Sub = sub(m_firstNumber, m_secondNumber);

                if(Sub->data == 0)
                    negResult = false;
                else 
                    negResult = true;
                
                print(Sub, negResult);
            }
            else {
                negResult = false;
                Sub = sub(m_secondNumber, m_firstNumber);
                print(Sub, negResult);
            }
           
        }

    } 
    // Если первое число положительно, а второе  отрицательно
    else if (f_sign == true && s_sign == false) {
            negResult = false;
            Sub = sum(m_firstNumber, m_secondNumber);
            print(Sub, negResult);

    }
    // Если первое число отрицательно, а второе положительно
    else if (f_sign == false && s_sign == true) {
        if (sizeNumber(m_firstNumber) == sizeNumber(m_secondNumber)) {
            bool firstBigger = compareNumbersForSub(m_firstNumber, m_secondNumber);
            if(firstBigger == true){
                negResult = true;
                Sub = sum(m_firstNumber, m_secondNumber);
                print(Sub, negResult);
            }
            else {
                negResult = true;
                Sub = sum(m_secondNumber, m_firstNumber);
                print(Sub, negResult);
            }
            
        }
        else {
            negResult = true;
            Sub = sum(m_firstNumber, m_secondNumber);
            print(Sub, negResult);
        }
    } 
    // Если оба числа положительны  
    else {
        if (sizeNumber(m_firstNumber) > sizeNumber(m_secondNumber)) {
            negResult = false;
            Sub = sub(m_firstNumber, m_secondNumber);
            print(Sub, negResult);
            
        }
        else if (sizeNumber(m_firstNumber) < sizeNumber(m_secondNumber)) {
            negResult = true;
            Sub = sub(m_secondNumber, m_firstNumber);
            print(Sub, negResult);
            
        }
        else if (sizeNumber(m_firstNumber) == sizeNumber(m_secondNumber)) {
            bool firstBigger = compareNumbersForSub(m_firstNumber, m_secondNumber);
            if(firstBigger == true){
                negResult = false;
                Sub = sub(m_firstNumber, m_secondNumber);
                
                print(Sub, negResult);
            }
            else {
                negResult = true;
                Sub = sub(m_secondNumber, m_firstNumber);
                print(Sub, negResult);
            }
           
        }
    }
}