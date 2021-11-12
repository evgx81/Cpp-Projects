#include <fstream>
#include <iostream>
#include "faculty.hh"
#include <cmath>

int main() {
    
    std::ifstream fin("students.txt", std::ios::in);
    if (!fin.is_open()) {
        std::cerr << "Unable to open file for reading!\n";
        return 1;
    }
    Faculty faculty;
    // Считываем факультет
    faculty.fill(fin);
    fin.close();
   
    // Выводим считанный факультет
    std::cout << faculty << '\n';

    double avgScore = faculty.averageScore("МС", 3);

    // Проверка существует ли такое значение
    if (std::isnan(avgScore))
        std::cout << "На факультете нет данного курса или предмета!\n";

    else
        // Выводим среднее значение заданной группе по заданному предмету
        std::cout << "Среднее значение: " << avgScore << '\n';    

    return 0;
}