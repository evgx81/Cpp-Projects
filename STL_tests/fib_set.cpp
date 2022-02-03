#include <iostream>
#include <set>
using namespace std;

//Дана последовательность чисел от 1 до 50 вкл.
//Сколько среди них чисел Фиббоначи?
//Проверить, явл. ли элементы введеного множества элементом последовательности Фиббоначи

int main(){
    int n = 0;
    std::cout << "Введите количество чисел в последовательности: ";
    std::cin >> n;

    set<int> s_fib;
    int prev_n = 1;
    int next_n = 1;

    s_fib.insert(prev_n);
    int inter = 0;
    while(inter < 50){
        inter = prev_n + next_n;
        s_fib.insert(inter);

        prev_n = next_n;
        next_n = inter;
    }

    set<int> input_s;
    int number = 0;
    for(int i = 0; i < n; i++){
        cin >> number;
        if(number >= 1 && number <= 50){
            input_s.insert(number);
            if(s_fib.count(number) == 1)
                cout << "Является" << endl;
            else
                cout << "Не является" << endl;
        }
    }

    return 0;
}