#include <iostream>

#include "hyperbola.hh"
#include  "ellipse.hh"
#include <stdexcept>

std::ostream& operator<<(std::ostream& os, Function& f) {
    os << f.showData();
    return os;
}

void calcFunction()
{
    bool condition = true;
    char ch;

    double a{0.0};
    double b{0.0};
    double x{0};

    while(condition) {

        condition = false;

        std::cout << "Выберете фигуру:\n";
        std::cout << "'1' - Эллипс\n";
        std::cout << "'2' - Гипербола\n";
        std::cout << "'q' - Выход\n"; 
            
        std::cout << "Ваш выбор: ";
        std::cin >> ch; 

        switch(ch) {
            case '1': {

                std::cout << "Большая полуось эллипса: ";
                std::cin >> a;
                std::cout << "Малая полуось эллипса: ";
                std::cin >> b;

                // Если введеные данные не удовлетворяют определению эллипса, кидаем исключение
                if(b >= a)
                    throw std::invalid_argument("Малая полуось больше или равна малой полуоси");
                if(a <= 0)
                    throw std::invalid_argument("Параметр 'a' должен быть положительным числом!");
                if(b <= 0)
                    throw std::invalid_argument("Параметр 'b' должнен быть положительным числом!");
               
                // Вводим x
                std::cout << "Введите x: ";
                std::cin >> x;

                Function* f = new Ellipse(a, b, x);

                // Выводим значение на экран
                std::cout << *f << '\n';

                delete f;

                condition = true;
                break;
            }
            case '2': {
                std::cout << "Действительная полуось гиперболы: ";
                std::cin >> a;
                std::cout << "Мнимая полуось гиперболы: ";
                std::cin >> b;

                // Вводим x
                std::cout << "Введите x: ";
                std::cin >> x;

                Function* f = new Hyperbola(a, b);

                // Выводим значение на экран
                std::cout << *f << '\n';

                delete f;

                condition = true;
                break;
            }
            case 'q': {
                std::cout << "Вы закончили пользоваться калькулятором." << '\n';
                condition = false;
                break;
            }
            default: {
                std::cout << "Выбранной фигуры в списке нет!" << '\n';
                std::cout << "Выберете другую фигуру или нажмите 'q', чтобы закончить выполнение вычислений" << '\n';
                condition = true;
            }
        }

        std::cout << '\n';
    }
}

int main()
{
    try
    {
        calcFunction();
    }
    catch(std::invalid_argument err)
    {
        std::cerr << err.what() << '\n'; 
    }

    return 0;
}