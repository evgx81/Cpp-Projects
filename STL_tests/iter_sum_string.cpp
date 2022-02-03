#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iterator>

//Есть файл, в нем через пробел имеются числа. 
//Надо посчитать сумму этих чисел и количество четный чисел.

int main() {
    
    std::ifstream file("digit_test.txt", std::ios::in);

    if (!file.is_open()) {
        std::cout << "Невозможно открыть файл\n";
        return 1;
    }

    //Для хранения чисел
    std::vector<int> numbers{};

    std::copy(std::istream_iterator<int>{file}, std::istream_iterator<int>{}, std::back_inserter(numbers));
    
    // Выводим полученный вектор на экран
    for (auto it = numbers.cbegin(); it < numbers.cend(); it++)
        std::cout << *it << " ";
    std::cout << "\n";

    for(auto elem : numbers)
        std::cout << elem << " ";
    std::cout << std::endl;

    std::copy(numbers.cbegin(), numbers.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    int sum{} ;
    int count{};

    for(auto it = numbers.cbegin(); it <= numbers.cend(); it++)
    {
        sum += *it;
        if (*it % 2 == 0)
            count++;
    }

    std::cout << "Сумма: " << sum << std::endl; 
    std::cout << "Кол-во четных чисел: " << count << std::endl;    


    return 0;
}
