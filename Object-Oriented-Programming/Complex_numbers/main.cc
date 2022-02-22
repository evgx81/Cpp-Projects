#include "complex.hh"

int main() {

    char c;

    std::cout << "Выберете операцию: " << '\n';
    std::cout << "1. Сложение" << '\n';
    std::cout << "2. Вычитание" << '\n';
    std::cout << "3. Произведение" << '\n';
    std::cout << "4. Деление" << '\n';
    std::cout << "5. Проверка на равенство" << '\n';
    std::cout << "6. Проверка на неравенство" << '\n';
    std::cout << "7. Присваивание " << '\n';
    std::cout << "8. Конструктор копирования " << '\n';

    std::cin >> c;

        switch (c) {
        case '1': {
            ComplexNumber a;
            std::cin >> a;

            ComplexNumber b;
            std::cin >> b;

            ComplexNumber c = a + b;

            std::cout << "Сумма чисел: " << c << std::endl; 
            break;
        }
        case '2': {
            ComplexNumber a;
            std::cin >> a;

            ComplexNumber b;
            std::cin >> b;

            ComplexNumber c = a - b;

            std::cout << "Разность чисел: " << c << std::endl; 
            break;
        }
        case '3': {
            ComplexNumber a;
            std::cin >> a;

            ComplexNumber b;
            std::cin >> b;

            ComplexNumber c = a * b;

            std::cout << "Произведение чисел: " << c << std::endl; 
            break;
        }
        case '4': {
            ComplexNumber a;
            std::cin >> a;

            ComplexNumber b;
            std::cin >> b;

            try {
                ComplexNumber c = a / b;
                std::cout << "Частное чисел: " << c << std::endl; 
            }
            catch (...) {
                std::cerr << "Деление на нуль!" << std::endl;
            }
            
            break;
        }
        case '5': {
            ComplexNumber a;
            std::cin >> a;

            ComplexNumber b;
            std::cin >> b;

            if (a == b)
                std::cout << "Комплексные числа равны" << '\n';
            else
                std::cout << "Комплексные числа не равны" << '\n';
            break;
        }
        case '6': {
            ComplexNumber a;
            std::cin >> a;

            ComplexNumber b;
            std::cin >> b;

            if (a != b)
                std::cout << "Комплексные числа не равны" << '\n';
            else
                std::cout << "Комплексные числа равны" << '\n';
            break;
        }
        case '7': {
            ComplexNumber a;
            std::cin >> a;

            ComplexNumber b;
            std::cin >> b;

            a = b;
            std::cout << "a = " << a << std::endl;
            std::cout << "b = " << b << std::endl;  
            break;
        }
        case '8': {
            ComplexNumber a;
            std::cin >> a;

            ComplexNumber b(a);

            a = b;
            std::cout << "a = " << a << std::endl;
            std::cout << "b = " << b << std::endl;  
            break;
        }
        default:
            std::cout << "В списке нет выбранной операции" << std::endl;
    }

    return 0;
}
