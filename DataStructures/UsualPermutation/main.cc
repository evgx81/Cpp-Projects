#include <iostream>
#include <fstream>
#include <set>
#include <string>
int main()
{
    try
    {

        // Открываем файл для считывания
        std::ifstream fin("text.txt", std::ios::in);
        if (!fin.is_open())
            throw "Unable to open file for reading!\n";
        // Заданные 2 строки
        std::string str1{};
        std::string str2{};
        // Пока не конец файла
        while(!fin.eof())
        {
            // Объявляем 2 множества
            std::multiset<char> set_str1;
            std::multiset<char> set_str2;
            // Нужная строка  
            std::multiset<char> x;
            // Считываем из файла 2 строки
            fin >> str1;
            fin >> str2;
            // Заносим каждую строку в множество
            for (int i = 0; i < str1.size(); i++)
                set_str1.insert(str1[i]);
            for (int i = 0; i < str2.size(); i++)
                set_str2.insert(str2[i]);


            std::multiset<char>::iterator elem;
            // Проходим по первой строке и рассматриваем каждый символ
            for (elem = set_str1.cbegin(); elem != set_str1.cend(); ++elem) {
                // Если в нужной строке x еще нет такого символа(для того чтобы избежать повторений), то с ним работаем
                // Иначе пропускаем этот символ
                if (x.count(*elem) == 0) {
                    // Находим минимальное значение количества этого символа в каждой строке
                    // Т.к этот элемент общий, то в любом случае минимальное кол-во этого символа из обоих строках будет входит в подстроку
                    int val = std::min(set_str1.count(*elem), set_str2.count(*elem));
                    // Пока можно занести символ в подстроку, заносим его туда
                    while (val != 0) {
                        x.insert(*elem);
                        val--;
                    }
                }
            }

            // Выводим исходную строку
            for (auto elem : x)
                std::cout << elem;
            std::cout << '\n';
        }

        fin.close();
        
        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}