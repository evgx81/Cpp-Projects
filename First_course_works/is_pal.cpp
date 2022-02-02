#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;
//Рекурсивно считать элементы из файла f и описать функцию pal(), которая
//проверяет является ли строка из файла - палиндромом.

//Проверка является ли строка палиндромом
string pal(const string& str){
    string rev_str{str}; // унифицированная инициализация
    reverse(rev_str.begin(), rev_str.end());
    
    if(rev_str == str)
        return " является палиндром";
    else
        return " не является палиндром";
}

static int line_number{1};

void recurs_reading(ifstream& file){
    if (!file.eof()) {
        string line{}; // унифицированная инициализация
        getline(file, line);
        cout << "Строка с номером " << line_number << pal(line) << endl;
        line_number++;
        recurs_reading(file);
    }
    else
        cout << "Конец чтения файла" << endl;
}

int main(){
    ifstream file("test.txt", std::ios::in);

    if(!file.is_open()){
        std::cerr << "Невозможно открыть файл" << std::endl; // Выводим ошибки в поток ошибок
        return 1;
    }

    recurs_reading(file);

    return 0;
}

