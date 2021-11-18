#include "CStudent.hh"
#include "CProfessor.hh"

#include <iostream>

int main() {
    CPerson* pPerson1 = new CPerson("Иванов", "Иван", "Иванович");
    CPerson* pPerson2 = new CStudent("Иванов", "Иван", "Иванович", 3.0, 2);
    CPerson* pPerson3 = new CProfessor("Иванов", "Сергей", "Петрович", 12, Lecturer, 50);

    pPerson1->ShowData(std::cout);
    pPerson2->ShowData(std::cout);
    pPerson3->ShowData(std::cout);

    std::cout << "----------------------------\n";

    CPerson person("Иванов", "Иван", "Иванович");
    CStudent student("Иванов", "Иван", "Иванович", 3.0, 2);
    CProfessor professor("Иванов", "Сергей", "Петрович", 12, Lecturer, 50);

    CPerson* pPerson;

    pPerson = &person;
    pPerson->ShowData(std::cout); // данные о студенте

    pPerson = &student;
    pPerson->ShowData(std::cout); // данные о профессоре

    pPerson = &professor;
    pPerson->ShowData(std::cout);

    std::cout << "----------------------------\n";

    CPerson p("Иванов", "Иван", "Иванович");
    p.ShowData(std::cout);

    CStudent s("Иванов", "Иван", "Иванович", 3.0, 2);
    s.ShowData(std::cout);

    delete pPerson1;
    delete pPerson2;
    delete pPerson3;
    
    return 0;
}