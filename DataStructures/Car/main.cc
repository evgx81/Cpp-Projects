#include <fstream>
#include <list>
#include "quadratic_probing.hh"

int main()
{
    std::ifstream fin("cars.txt", std::ios::in);
    if (!fin.is_open()) {
        std::cerr << "Unable to open file for reading!\n";
        return 1;
    }

    // Инициализируем хэш-таблицу
    QuadraticProbingTable hash_table(9);

    // Помещаем считанный объект в хэш-таблицу
    Car car;
    while(!fin.eof())
    {
        fin >> car;
        hash_table.insert(car.get_key(), car);
    }

    fin.close();

    // Выводим данные, считанные из файла
    hash_table.print();

    bool condition = true;
    char operation;

  

    while(condition) 
    {

        condition = false;

        std::cout << "Выберете операцию: " << '\n';
        std::cout << "'1' - Вставка элемента по ключу" << '\n';
        std::cout << "'2' - Удаление элемента по ключу" << '\n';
        std::cout << "'3' - Поиск элемента по ключу" << '\n';
        std::cout << "'4' - Печать таблицы" << '\n';
        std::cout << "'5' - Очистка таблицы" << '\n';
        std::cout << "'6' - Проверка пуста ли таблица" << '\n';
        std::cout << "'7' - Проверка находится ли элемент в таблице" << '\n';
        std::cout << "'8' - Определение размера таблицы" << '\n';
        std::cout << "'q' - Выход из программы" << '\n';

        std::cout << "Введите операцию: ";
        std::cin >> operation; 

        std::cout << '\n';

        Car test_car("MMM", 786213, "BMMO", "А.П.Репников", 16, ROUTE);

        switch(operation)
        {
            case '1':
            {
                hash_table.insert(test_car.get_key(), test_car);
                hash_table.print();
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '2':
            {
                bool isRemoved = hash_table.remove(test_car.get_key());
                if (isRemoved == true)
                    std::cout << "Элемент успешно удален\n";
                else
                    std::cout << "Элемента с ключом: " << test_car.get_key() << " нет в таблице\n";
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '3':
            {
                try
                {
                    Car m_value = hash_table.get(test_car.get_key());
                    std::cout << "Элемент с заданным ключом: " << m_value << '\n';
                }
                catch(std::range_error err)
                {
                    std::cerr << err.what() << '\n'; 
                }
        
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '4':
            {
                hash_table.print();
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '5':
            {
                hash_table.clear();
                hash_table.print();
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '6':
            {
                bool isEmpty = hash_table.isEmpty();
                if (isEmpty == true)
                    std::cout << "Таблица пуста\n";
                else
                    std::cout << "В таблице есть элементы\n";
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '7':
            {
                bool isFound = hash_table.find(test_car.get_key());
                if (isFound == true)
                    std::cout << "Элемент находится в таблице\n";
                else
                    std::cout << "Элемента с ключом: " << test_car.get_key() << " нет в таблице\n";
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case '8':
            {
                std::cout << "Количество элементов в таблице: " << hash_table.size() << '\n';
                std::cout << '\n' << '\n';
                condition = true;
                break;
            }
            case 'q': {
                std::cout << "Вы закончили пользоваться программой." << '\n';
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