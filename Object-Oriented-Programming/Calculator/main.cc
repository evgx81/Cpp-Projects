#include "fraction.hh"
#include "calculator.hh"

int main() {
    Fraction f1;
    Fraction f2;

    try {
        std::cin >> f1;
        std::cin >> f2;
        
    }
    catch(std::invalid_argument err){
        std::cerr << err.what() << '\n';
        return 1;
    }

    bool condition = true;
    char operation;

    while(condition) {

        condition = false;

        std::cout << "Выберете операцию: " << '\n';
        std::cout << "'+' - Сложение" << '\n';
        std::cout << "'-' - Вычитание" << '\n';
        std::cout << "'*' - Произведение" << '\n';
        std::cout << "'>' - Определение большей из дробей" << '\n';
        std::cout << "'<' - Определение меньшей из дробей" << '\n';
        std::cout << "'=' - Равенство дробей" << '\n';
        std::cout << "'!' - Неравентсво дробей" << '\n';
        std::cout << "'q' - Выход из программы" << '\n';
            
        std::cout << "Введите операцию: ";
        std::cin >> operation; 

       

        switch(operation) {
            case '+': {
                Calculator calc(f1, f2, '+');
                std::cout << "Результат сложения: ";
                calc.printResult(std::cout);
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '-': {
                Calculator calc(f1, f2, '-');
                std::cout << "Результат разности: ";
                calc.printResult(std::cout);
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '*': {
                Calculator calc(f1, f2, '*');
                std::cout << "Результат произведения: ";
                calc.printResult(std::cout);
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '>': {
                Calculator calc(f1, f2, '>');
                std::cout << "Результат сравнения: ";
                calc.printResult(std::cout);
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '<': {
                Calculator calc(f1, f2, '<');
                std::cout << "Результат сравнения: ";
                calc.printResult(std::cout);
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '=': {
                Calculator calc(f1, f2, '=');
                std::cout << "Результат проверки на равенство: ";
                calc.printResult(std::cout);
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '!': {
                Calculator calc(f1, f2, '!');
                std::cout << "Результат проверки на неравенство: ";
                calc.printResult(std::cout);
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
    
    return 0;
}