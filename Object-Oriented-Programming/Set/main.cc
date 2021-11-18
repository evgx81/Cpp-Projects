#include "set.hh"

void set_interface()
{
    Set<int> s1(5), s2(10);

    for (int i = 1; i < 6; ++i)
        s1.insert(i);

    for (int i = 0; i < 10; ++i)
        s2.insert(i);

    std::cout << s1;
    std::cout << s2;

    bool condition = true;
    char operation;

    while(condition) {

        condition = false;

        std::cout << "\nВыберете операцию: \n";
        std::cout << "'1' - Включение элемента в множество\n";
        std::cout << "'2' - Исключение элемента из множества\n";
        std::cout << "'3' - Объединение множеств\n";
        std::cout << "'4' - Пересечение множеств\n";
        std::cout << "'5' - Вычитание множеств\n";
        std::cout << "'6' - Отслеживание количества элементов в множестве\n";
        std::cout << "'7' - Проверка присутствия элемента в множестве\n";
        std::cout << "'8' - Проверка включения одного множества в другое\n";
        std::cout << "'q' - Выход из калькулятора\n";
            
        std::cout << "Введите операцию: ";
        std::cin >> operation; 


        switch(operation) {
            case '1': {
                int elem{};
                std::cout << "Введите элемент: ";
                std::cin >> elem;
                s1.insert(elem);
                std::cout << s1;
                condition = true;
                break;
            }
            case '2': {
                int del{};
                std::cout << "Введите элемент для удаления: ";
                std::cin >> del;
                s1.erase(del);
                std::cout << s1;
                condition = true;
                break;
            }
            case '3': {
                Set<int> s3 = s1.set_union(s2);
                std::cout << s3;
                condition = true;
                break;
            }
            case '4': {
                Set<int> s3 = s1.set_intersection(s2);
                std::cout << s3;
                condition = true;
                break;
            }
            case '5': {
                Set<int> s3 = s2.set_difference(s1);
                std::cout << s3;
                condition = true;
                break;
            }
            case '6': {
                int count = s1.size();
                std::cout << s1;
                std::cout << count;
                condition = true;
                break;
            }
            case '7': {
                int num{};
                std::cout << "Введите число: ";
                std::cin >> num;
                bool flag =  s1.find(num);
                if (flag == true)
                    std::cout << "Число " << num << " является элементом множества\n";
                else
                    std::cout << "Число " << num << " не является элементом множества\n";
                condition = true;
                break;
            }
            case '8': {
                bool flag = s1.is_subset(s2);
                if (flag == true)
                    std::cout << "Является подмножеством\n";
                else
                    std::cout << "Не является подмножеством\n";
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
}

int main()
{   

    try
    {
        set_interface();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}