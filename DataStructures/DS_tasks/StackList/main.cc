#include "stack.hh"
#include <iostream>
#include <string>
using namespace std;

//-----Получаем значение постфиксной записи
int calc(int x, int y, char op)
{
    int res = 0;
    switch(op)
    {
        case '+':
            res = x + y;
            break;
        case '-':
            res = x - y;
            break;
        case '*':
            res = x * y;
            break;
        case '/':
            res = x / y;
            break;
    }

    return res;
}

int getValuePostfixString(string s)
{
    int x, y;
    TStack top;
    init(top);
    for(int i = 0; i < s.size(); i++)
    {
        // Если цифра, то кладем в стек
        if(s[i] >= '0' && s[i] <= '9')
            push(top, s[i] - '0');
        else
        {
            y = peek(top);
            pop(top);
            x = peek(top);
            pop(top);
            int res = calc(x, y, s[i]);
            push(top, res);
        }
    }
    // Возвращаем последний элемент стека
    return peek(top);
}

//------Из инфиксной записи получаем постфиксную запись
string InfixToPostfix(string prefix)
{
    TStack st;
    init(st);
    string postfix;
    for(int i = 0; i < prefix.size(); i++)
    {
        // Если символ не число
        if(prefix[i] >= '0' && prefix[i] <= '9')
            postfix += prefix[i];
        else 
        {
            if(prefix[i] == ')')
            {
                while(peek(st) != '(')
                    postfix += peek(st);
                    pop(st);
                pop(st);
            }
            else 
                push(st, prefix[i]);
        }
    }   
    while(!isEmpty(st)) {
        postfix += peek(st);
        pop(st);
    }

    return postfix;
}

void writeBetweenMinAndMax()
{
    TStack top;
    init(top);
    int min = 0, max = 0;
    int a;
    cin >> a;
    min = a;
    max = a;
    push(top, a);
    while(a != 0)
    {
        if(a > max) a = max;
        if(a < min) a = min;
        push(top, a);
        cin >> a;
    }
    while(!isEmpty(top) && peek(top) != max &&  peek(top) != min)
        pop(top);   
    pop(top);
    while(!isEmpty(top) && peek(top) != max &&  peek(top) != min)
    {
        cout << peek(top);
        pop(top);
    }
}

TStack delDublicates(TStack& stack, TStack& tmp, TStack& res)
{
    // Если первоначальный список пуст, то выходим из рекурсии и возвращаем результат
    if(isEmpty(stack))
        return res;
    else
    {
        int num = peek(stack);
        pop(stack);
        push(res, num);
        while(!isEmpty(stack))
        {
            int tmpNum = peek(stack);
            pop(stack);
            if(tmpNum != num)
            {
                push(tmp, tmpNum);
            }
        }
        // Соблюдение порядка
        while(!isEmpty(tmp)) {
            push(stack, peek(tmp));
            pop(tmp);
        }
           
        return delDublicates(stack, tmp, res);
    }
}

// void printWordsOfMaxLength(TStack& top)
// {
//     init(top);
//     std::string str;
//     getline(cin, str);
    // push(top, str);
    // while(str != ".")
    // {
    //     getline(cin, str);
        // if(str.size() > peek(top).size())
        // {
        //     clear(top);
        //     push(top, str);
        // }
        // else if (str.size() == peek(top).size())
        // {
        //     push(top, str)
        // }
//     }
// }

int main()
{
    TStack top;
    init(top);
    // Вводим числа, в стеке они будут в обратном порядке
    int a{};
    cin >> a;
    push(top, a);
    while(a != 0)
    {
        push(top, a);
        cin >> a;
    }
    TStack tmp;
    init(tmp);
    TStack res;
    init(res);
    res = delDublicates(top, tmp, res);
    print(res);
    
    return 0;
}