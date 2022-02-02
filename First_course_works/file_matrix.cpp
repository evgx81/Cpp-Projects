#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

// Вывести среднее арифметическое наибольшего и наименьшего элементов, расположенных под главной диагональю

int main(){
    ifstream file("test.txt", std::ios::in);

    if(!file.is_open()){
        std::cout << "Невозможно открыть файл" << std::endl;
        return 1;
    }

    //Выделяем память под динамический массив
    int **matr = new int*[6];
    for(int i = 0; i < 6; i++)
        matr[i] = new int[9];


    //Считывание матрицы из файла
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            file >> matr[i][j];                
        }
    }

    
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            cout << matr[i][j] << "\t";
        }
        cout << "\n";
    }

    for(int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if(i > j)
                cout << matr[i][j] << "\t";
        }
        cout << "\n";
    }

    cout << "\n";

    int min = matr[1][0];
    int max = matr[1][0];
    for(int i = 0; i < 6; i++){
        for (int j = 0; j < 9; j++){
            if(i > j){
                if(matr[i][j] > max)
                    max = matr[i][j];

                if(matr[i][j] < min)
                    min = matr[i][j];

            }
        }
    }

    cout << "\n";
    cout << "Среднее арифметическое наибольшего элемента" << max << " и наименьшего элемента " << min << " расположенных ниже главной диагонали: " << double(max) / min << endl;
    cout << "\n";

    for(int i = 0; i < 6; i++)
        delete[] matr[i];
    delete[] matr;
    return 0;
}