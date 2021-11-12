#ifndef GROUP_H
#define GROUP_H

#include "student.hh"
// #include <list>
#include "list.hh"

class Group
{
    // Номер группы
    int m_groupNumber;
    // Количество студентов
    int m_countStudents;
    // Список студентов
    List<Student> m_groupStudents;
public:
    Group() : m_groupNumber{}, m_countStudents{} {} 
    // ~Group() { std::cout << "Здесь деструктор Group\n"; }
public:
    friend std::ostream& operator<<(std::ostream&, const Group&);
public:
    // Получаем номер группы
    int getGroupNumber()
    {
        return m_groupNumber;
    }
    // Задаем значение новой группы
    void setGroup(int group)
    {
        m_groupNumber = group;
    }
    // Заполняем список студентов в группе
    void addStudent(Student*);

    bool isSubjectInGroup(const std::string&);

    // Для конкретной группе вычисляем средний балл
    double averageScoreOfGroup(const std::string&);
    
};

#endif