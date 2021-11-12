#ifndef FACULTY_H
#define FACULTY_H

#include "course.hh"

class Faculty
{
    // Название факультета
    std::string m_nameFaculty;
    // Массив курсов
    Course* m_facultyCourses;
public:
    Faculty() : m_nameFaculty{}
    {
        // Инициализируем массив курсов
        m_facultyCourses = new Course[6];
        for(int i = 1; i <= 6; i++)
            // Присваеваем курсам факультета номера
            m_facultyCourses[i-1].setCourseNumber(i);
    }
    ~Faculty() 
    {
        delete[] m_facultyCourses;
        // std::cout << "Здесь сработал деструктор класса Faculty\n";
    }
public:
    friend std::ostream& operator<<(std::ostream&, const Faculty&);
public:
    // Функция вычисляет средний балл по заданному предмету, на заданном курсе.
    double averageScore(const std::string&, int);
    // Функция заполняет факультет
    void fill(std::ifstream&);
};

#endif