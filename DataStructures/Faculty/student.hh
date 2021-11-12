#ifndef STUDENT_H
#define STUDENT_H

#include "subject.hh"

class Student 
{
    // ФИО студента
    std::string m_fio;
    // Форма обучения
    std::string m_form;
    // Успеваемость
    Subject* m_results;

public: 
    // Конструктор по умолчанию
    Student() : m_fio{}, m_form{} 
    {   
        m_results = new Subject[5];
    }
    // Конструктор копирования
    Student(const Student& student)
    {
        m_fio = student.m_fio;
        m_form = student.m_form;
        m_results = new Subject[5];
        for(int i = 0; i < 5; i++)
            m_results[i] = student.m_results[i];

    }
    // Деструктор
    ~Student() 
    { 
        // std::cout << "Здесь сработал деструктор Student\n";
        delete[] m_results; 
    }
public:
    friend std::istream& operator>>(std::istream&, Student&);
    friend std::ostream& operator<<(std::ostream&, const Student&);
public:
    // Найдем заданный предмет у студента
    bool isSubjectInStudent(const std::string&);
    // Возвращаем оценку студента по заданному предмету
    int getStudentMark(const std::string&);
};

#endif