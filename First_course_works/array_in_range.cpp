#include <iostream>

using namespace std;

/*Динамические массивы

    Для всех задач: Массив задается рандомно

    1. Посчитать количество и сумму элементов массива, принадлежащих интервалу, который
задает пользователь.

*/

int main(){

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    int *matrix;

    matrix = new int[size];

    for(int i = 0; i < size; i++)
        matrix[i] = rand() % 20;

    int a;
    int b;

    std::cout << "Введите левую границу интревала: ";
    cin >> a;

    std::cout << "Введите правую границу интревала: ";
    cin >> b;

    for(int i = 0; i < size; i++) 
        std::cout << matrix[i] << " ";

    int count = 0;
    int sum = 0;

    for(int i = 0; i < size; i++){
        if(matrix[i] >= a && matrix[i] <= b){
            count++;
            sum += matrix[i];
        } 
    }

    std::cout << "\n";

    std::cout << "Кол-во элементов в массиве: " << count << std::endl;
    std::cout << "Сумма элементов массива: " << sum << std::endl;

    delete [] matrix;
    return 0;
}