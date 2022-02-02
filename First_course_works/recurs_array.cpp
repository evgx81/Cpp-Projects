#include <iostream>

void print(int* mass, const int& m, const char* str){
    std::cout << "\n";
    std::cout << str << std::endl;
    for(int i = 0; i < m; i++)
        std:: cout << mass[i] << " ";
    std::cout << "\n";
}


void mod(int* arr, const int& size){
    if(arr[size] % 7 < 7 && size >= 0){
        arr[size] = arr[size] % 7;
        mod(arr, size - 1);    
    }
    else
        arr[size] = arr[size] % 7;
}

int main(){
    int n{0};
    std::cout << "Введите количество элементов в массиве: ";
    std::cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 901 - 100;

    print(arr, n, "Исходный массив");

    int* mods = new int[n];
    
    //Рекурсивная функция передачи элементов массива в функцию и их проверка их на кратность
    mod(arr, n - 1);
    
    print(arr, n, "Массив остатков от деления на 7");

    delete[] arr;

    return 0;
}