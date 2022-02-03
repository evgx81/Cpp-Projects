#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iterator>

// Есть вектор целых чисел. Надо посчитать сумму элементов, среднее, а также все числа, которые делятся на 3 без остатка.
// std::accumulate(), std::for_each(), std::copy_if()

int main(){
    std::vector<int> numbers = {1, 3, 0, -9, 5, 6, -7};

    //std::accumulate() - возвращает с сумму прибавления каждого элемента вектора к 0 
    int sum = std::accumulate(numbers.cbegin(), numbers.cend(), 0);
    std::cout << "Сумма элементов: " << sum << std::endl;


    std::cout << "Среднее: "<< double(sum) / numbers.size() << std::endl;

    std::vector<int> numbers_3;
    //Заполняется вектор numbers_3 значениями из вектора numbers при условии их кратности 3   
    copy_if(numbers.begin(), numbers.end(), std::back_inserter(numbers_3), [](const int x){return (x % 3 == 0);});

    std::cout << "Числа кратные 3: "; 
    //Обращается к каждому элементу вектора
    for_each(numbers_3.cbegin(), numbers_3.cend(), [](const int& val){std::cout << val << " ";});
    return 0;
}