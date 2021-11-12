#include "List.hh"
#include "longNumbersFunctions.hh"

#include <iostream>
#include <fstream>
 

int main() {

    std::ifstream file("longNumbers.txt", std::ios::in);
    if (!file.is_open()) {
        std::cerr << "Невозможно открыть файл для чтения" << '\n';
        return 1;
    }
    // Каждый лист будет содержать цифры длинных числа
    TList m_firstNumber;
    TList m_secondNumber;

    init(m_firstNumber);
    init(m_secondNumber);

    // В отдельных bool-переменных будем хранить знаки чисел
    // Допустим, что оба числа положительные
    // true = +
    // false = -
    bool f_sign = true;
    bool s_sign = true;     

    std::string f_number;
    std::string s_number;

    // Считали из файла слово
    file >> f_number;
    file >> s_number;

    readNumberFromFile(m_firstNumber, f_number, f_sign);
    readNumberFromFile(m_secondNumber, s_number, s_sign);

    bool condition = true;
    char operation;

    while(condition) {
        condition = false;

        std::cout << "Выберете операцию: " << '\n';
        std::cout << "'+' - Сложение" << '\n';
        std::cout << "'-' - Вычитание" << '\n';

        std::cout << "Введите операцию: ";
        std::cin >> operation; 

        switch(operation) {
            case '+': {
                std::cout << "Результат суммы чисел " << f_number << " и " << s_number << " равен ";
                printSum(m_firstNumber, m_secondNumber, f_sign, s_sign);
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '-': {
                std::cout << "Результат разности чисел " << f_number << " и " << s_number << " равен ";
                printSub(m_firstNumber, m_secondNumber, f_sign, s_sign);
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case 'q': {
                std::cout << "Вы закончили пользоваться калькулятором." << '\n';
                condition = false;
                break;
            }
            default: {
                std::cout << "Выбранной операции с списке нет!" << '\n';
                std::cout << "Выберете другую операцию или нажмите 'q', чтобы закончить выполнение вычислений" << '\n';
                condition = true;
            };
            std::cout << '\n';
        }
    
    }

    file.close();
    return 0;
}