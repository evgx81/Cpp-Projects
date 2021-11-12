#ifndef COURSE_H
#define COURSE_H

#include "group.hh"

class Course
{
    // Номер курса
    int m_courseNumber;
    // Кол-во групп 
    int m_countGroups;
    // Список, содержащий список групп
    List<Group> m_courseGroups;
public:
    Course() : m_courseNumber{}, m_countGroups{}, m_courseGroups{} {}
    // ~Course() { std::cout << "Здесь деструктор Course\n"; }
public:
    friend std::ostream& operator<<(std::ostream&, const Course&);
public:
    // Устанавливаем значение курса
    void setCourseNumber(int course)
    {
        m_courseNumber = course;
    }
    void increaseCourseGroups()
    {
        m_countGroups++;
    }
    // Добавляем новую группу в список групп
    void addGroup(const Group&);
    // Находим группу в списке групп
    Group* findGroupByNumber(int);
    // Проверим, есть ли заданная группа в списке групп
    bool isGroupInList(int);
    // Вычисляем среднее арифметическое оценок на курсе
    double getAvarageScore(const std::string&);
};

#endif
