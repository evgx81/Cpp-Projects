#include <iostream>
#include <iomanip>

// Дано натуральное число n и вещественная матрица размера n X 9 . 
// Найти среднее арифметическое: каждого из столбцов, имеющих четные номера.

int main(){
    const int cols = 9; //Порядок матрицы

    int rows;
    std::cout << "Введите кол-во строк: ";
    std::cin >> rows;

    int matr[rows][cols];

    std::cout << "Введите элементы матрицы: ";
    std::cout << std::endl;
    for(int i = 0; i < rows; i++){

        for(int j = 0; j < cols; j++){
            //cin >> matr[i][j];
            matr[i][j] = std::rand() % 50;
        }
    }

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {
            
            std::cout << std::setw(8) << matr[i][j];

        }

        std::cout << "\n";
    }

    int sum = 0;

    int g = 0;

    std::cout << "\n";

    std::cout << "Среднее арифметическое четных столбцов: ";
    while(g < cols){

        for(int i = 0; i < rows; i++){
            sum += matr[i][g]; 
        }

        std::cout << (double) sum / rows << "\t";

        sum = 0;
        g = g + 2;
    }


    return 0; 
}