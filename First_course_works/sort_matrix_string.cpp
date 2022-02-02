#include <iostream>
#include <iomanip>

using namespace std;

// Сортировка заданной строки матрицы

//init - функция заполнения двухмерного массива
void init(int** mass, const int rows, const int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            mass[i][j] = rand() % 100; 
        }
    }
}

//print - функция печатания двухмерного массива
void print(int** mass, const int rows, const int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << mass[i][j] << "\t"; 
        }
        cout << "\n";
    }
}

//sort - функция сортировки двухмерного массива методом Шелла
void sort(int** mass, const int cols, const int ptr){
    int d = cols / 2;

    int t = 0;
    int l = 0;
    while(d > 0){
            for(int j = 0; j < cols - d; j++){
                l = j;
                while(l >= 0 && mass[ptr][l] > mass[ptr][l + d]){
                    t = mass[ptr][l];
                    mass[ptr][l] = mass[ptr][l+d];
                    mass[ptr][l+d] = t;
                    l--;
                }    
            }
        d = d / 2;
    }
}

int main(){

    int n, m;
    cout << "Введите кол-во строк: ";
    cin >> n;

    cout << "Введите кол-во столбцов: ";
    cin >> m;

    int **arr = new int*[n]; //Создание строк
    for(int i = 0; i < n; i++)
        arr[i] = new int[m]; //Выделение памяти под колонки для каждой строки



    init(arr, n, m);
    print(arr, n, m);

    cout << "\n";

    int p; //Строка матрицы для сортировки
    cout << "Введите строку для сортировки: ";
    cin >> p;

    if(p < 0 || p >= n){
        cout << "Неверный ввод данных!";
        return 0;
    }

    sort(arr, m, p);
    print(arr, n, m);

    for(int i = 0; i < n; i++){
        delete[] arr[i]; //Освобождение памяти, выделенной под столбцы
    }

    delete[] arr; //Освобождаем память, выделенную под строки    

    return 0;
}