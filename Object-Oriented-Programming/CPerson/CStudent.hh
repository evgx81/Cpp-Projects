#ifndef H_STUDENT
#define H_STUDENT

#include "CPerson.hh"
#include <iostream>

class CStudent : public CPerson 
{
    double m_avScore;
    int m_course;
public:
    CStudent(std::string firstName, std::string secondName, std::string lastName, double avScore, int course) : CPerson(firstName, secondName, lastName), m_avScore(avScore), m_course(course) {};
public:
    void ShowData(std::ostream&);
};

#endif