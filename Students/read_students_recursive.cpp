#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <iterator>
#include <algorithm>
#include <exception>
#include <array>
#include <cmath>
#include <sstream>

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

    friend istream &operator>>(istream &is, Student &student) {
        is >> student.fio >> student.course >> student.group;
        for (auto& mark : student.marks)
            is >> mark;
        return is;
    }

    auto GetAvMark() const {
        return accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
    }
};

void WriteStudentsToFile() {
    vector<Student> students{{"Ivanov", 2, 1, {3, 3, 4}},
                             {"Petrov", 2, 4, {5, 3, 4}},
                             {"Sidorov", 3, 61, {4, 5, 5}}
    };

    ofstream fout("students.txt", ios::out);
    if (!fout.is_open()) {
        throw ios_base::failure("Unable to write student in file: file open error");
    }

    for_each(students.begin(), students.end(), [&fout](Student& student){ fout << student; });
}

// Правильное чтение из файла
vector<Student> ReadStudentsFromFile() {
    ifstream fin("students.txt");
    if(!fin.is_open()){
        throw ios_base::failure("Unable to open file for reading");
    }

    vector<Student> students;
    copy(istream_iterator<Student>(fin), istream_iterator<Student>(), back_inserter(students));

    return students;
}

void ReadStudentsFromFileRecursive(ifstream &file, vector<Student>& students) {
    
    if (!file.eof()) {
        string line{};
        getline(file, line);
        if (!line.empty()) {
            stringstream ss;
            ss << line;
            Student student{};
            ss >> student;
            if (!student.fio.empty() && student.group != 0 && student.course != 0 && !(student.GetAvMark() < numeric_limits<double>::epsilon())) {
                students.push_back(student);
            }
        }
        ReadStudentsFromFileRecursive(file, students);
    }
}

void SplitStudents(const vector<Student> students) {

    ofstream file1("marks5.txt");
    ofstream file2("marks3-5.txt");
    ofstream file3("markRest.txt");

    if (!file1.is_open() || !file2.is_open() || !file3.is_open()) {
        throw ios_base::failure("Unable to open file for writing!");
    }
    copy_if(students.cbegin(), students.cend(), ostream_iterator<Student>(file1), 
        [](const Student& s){
            cout << s.GetAvMark() << endl;
            return fabs(s.GetAvMark() - 5.0) <= numeric_limits<double>::epsilon(); // средняя оценка 5
        }
    );

    copy_if(students.cbegin(), students.cend(), ostream_iterator<Student>(file2),
        [](const Student& s) {
            auto avgMark = s.GetAvMark();
            return (avgMark > 3.0) && (avgMark < 5.0); // средняя оценка между 3 и 5
        }
    );

    copy_if(students.cbegin(), students.cend(), ostream_iterator<Student>(file3), 
        [](const Student& s){
            return s.GetAvMark() <= 3.0; // средняя оценка меньше или равна 3
        }
    );
    
}

int main()
{
    try {
        // Записываем несколько студентов в файл
        // WriteStudentsToFile();

        // ПРАВИЛЬНОЕ чтение из файла
        // auto students = ReadStudentsFromFile();

        // НЕПРАВИЛЬНОЕ рекурсивное чтение из файла
        ifstream fin("students.txt");
        if (!fin.is_open()) {
            throw ios_base::failure("Unable to open file for reading");
        }
        vector<Student> students;
        ReadStudentsFromFileRecursive(fin, students);

        SplitStudents(students);
    }
    catch(ios_base::failure& ex) {
        cerr << ex.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}