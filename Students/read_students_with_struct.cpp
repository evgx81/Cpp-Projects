#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <array>
#include <string>
#include <memory>
#include <iterator>
#include <algorithm>

/*
*/

using namespace std;

struct Student
{
    string fio;
    int course;
    int group;
    array<int, 3> marks;

    Student(string fio, int course, int group, const array<int, 3> &marks) :
        fio(move(fio)), course(course), group(group), marks(marks) {}

    friend ostream &operator<<(ostream &os, const Student &student) {
        os << student.fio << '\n' << student.course << '\n' << student.group << '\n';
        for (auto mark : student.marks)
            os << mark << " ";
        os << endl;
        return os;
    }
 
    friend istream &operator>>(istream &is, Student &student) {
        is >> student.fio >> student.course >> student.group;
        for (auto& mark : student.marks)
            is >> mark;
        return is;
    }
};

void ReadStudentsFromFile() {
    ifstream fin("students.txt", std::ios::in);
    if (!fin.is_open()) {
        cerr << "Unable to open file for writing!\n";
        return;
    }

    vector<Student> students;
    for_each(students.begin(), students.end(), [&fin](auto& student){ fin >> student; });
    
    fin.close();
}

int main(){

    // Считываем студентов в файла
    ReadStudentsFromFile();
    return 0;    
}