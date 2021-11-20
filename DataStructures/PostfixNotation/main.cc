#include "tree.hh"
#include "stack.hh"
#include <fstream>
#include <sstream>

// Проверка на знак
bool isSign(char sign)
{
    return (sign == '+' || sign == '*') ? true : false;
}

// Проверка на операнд
bool isOperand(char operand)
{
    return (operand >= 'A' && operand <= 'Z') ? true : false;
}

// Проверка правильности постфиксной записи
bool CheckPostfixCorrectness(std::string postfix)
{
    // Допустим, что изначально запись правильная
    bool flag = true;
    // Создаем дерево исходное постфиксное дерево
    TTree tree;
    // Стек будет хранить все поддеревья, которые удовлетворяют условиям
    Stack<TTree> stack;
    // Строковый поток для получения символа
    std::stringstream ss(postfix);
    char ch{};
    // Пока можем считать символ и запись считается правильной, будем проверять условия
    while(ss >> ch && flag == true)
    {
        // Если символ является заглавной латинской буквой, то создаем новую вершину у дерева, а сам символ заносим в стек
        if (isOperand(ch))
        {
            init(tree, ch);
            stack.push(tree);
        }
        else if (ch == '-')
        {
            init(tree, ch);
            if(!stack.isEmpty())
                attachLeftSubtree(tree, stack.peek());
            else
                flag = false;
        }
        // Если символ является знаком
        else
        {
            TTree leftTree;
            init(leftTree);
            TTree rightTree;
            init(rightTree);

            // Вытаскиваем из стека 2 поддерева и копируем их в соответсвующие деревья
            // Если 2 стеке меньше 2-х поддеревьев то запись будет неправильной
            if (!stack.isEmpty())
            {
                copyTree(stack.peek(), leftTree);
                stack.pop();
            }
            else
                flag = false;
              
            if (!stack.isEmpty())
            {
                copyTree(stack.peek(), rightTree);
                stack.pop();
            }
            else
                flag = false;  
            // Если в стеке было 2 поддерева, то присоединяем их к вершине с значением знака
            if (flag != false)
            {
                init(tree, ch, leftTree, rightTree);
                stack.push(tree);
            }

        }

    }
    // Если после работы программы в стек не пуст, то удаленный элемент будет являться исходным постфиксным деревом
    if (!stack.isEmpty())
        stack.pop();
    else
        flag = false;

    // Если после выполнения цикла в стеке осталось 2 поддерева, то запись будет неверной
    if (!stack.isEmpty())
        flag = false;


    return flag;  
}

int main()
{
    try
    {
        // Постфиксная строка
        std::string postfix{};
        // Открываем файл для считывания
        std::ifstream fin("postfix.txt", std::ios::in);
        if (!fin.is_open())
            throw "Unable to open file for reading!\n";
        // Считываем строку
        getline(fin, postfix, '\n');
        fin.close();
        // Проверяем правильность постфиксной записи
        bool isPostfix = CheckPostfixCorrectness(postfix);
        if (isPostfix == true)
            std::cout << "Строка " << postfix << " является постфиксным выражением\n";
        else
            std::cout << "Строка " << postfix << " не является постфиксным выражением\n";
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}