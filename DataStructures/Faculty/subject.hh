#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <fstream>
#include <string>

struct Subject
{
private:
    std::string m_name;
    int m_mark;
public:
    Subject() : m_name{}, m_mark{} {};
    Subject(const Subject& subject)
    {
        m_name = subject.m_name;
        m_mark = subject.m_mark;
    }
public:
    friend std::istream& operator>>(std::istream&, Subject&);
    friend std::ostream& operator<<(std::ostream&, const Subject&);
public:
    // Получаем предмет
    std::string getSubjectName()
    {
        return m_name;
    }
    // Получаем оценку
    int getMark()
    {
        return m_mark;
    }
};

#endif