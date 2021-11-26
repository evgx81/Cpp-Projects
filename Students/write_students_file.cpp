#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>
#include <array>

/*В файле содержится информация об учениках различных курсов:
ФИО, курс, группа, оценки(2, 3, 4, 5) по 3 предметам.
Записать информацию об учениках в 3 различных файла(только отличники, между 3 и 5, 3 и ниже)
Обязательно использовать: Структура, Рекурсия, Функции
*/

using namespace std;

struct Student
{
    string fio;
    int course;
    int group;
    array<int, 3> marks;

    Student() = default;

    Student(string fio, int course, int group, const array<int, 3> &marks) :
        fio(move(fio)), course(course), group(group), marks(marks) {}

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << student.fio << " " << student.course << " " << student.group << " ";
        for (auto mark : student.marks)
            os << mark << " ";
        os << endl;
        return os;
    }
};

void WriteStudentsToFile() {
    vector<Student> students{{"Ivanov", 2, 1, {3, 3, 4}},
                             {"Petrov", 2, 4, {5, 3, 4}},
                             {"Sidorov", 3, 61, {4, 5, 5}}
    };

    ofstream fout("students.txt", ios::out);
    if (!fout.is_open()) {
        throw ios_base::failure("Unable to open file for writing!");
    }

    for_each(students.begin(), students.end(), [&fout](Student& student){ fout << student; });
}


int main(){

    // Записываем несколько студентов в файл
    try {
        WriteStudentsToFile();
    }
    catch(ios_base::failure& ex) {
        cerr << ex.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
