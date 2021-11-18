#ifndef H_PROFESSOR
#define H_PROFESSOR

#include "CPerson.hh"
#include <iostream>

enum Post 
{
    Lecturer,
    Senior_lecturer,
    Docent,
    Professor
};

class CProfessor : public CPerson
{
    int m_countPublications;
    Post m_post;
    int m_age;
public:
    CProfessor(std::string firstName, std::string secondName, std::string lastName, int countPublications, Post post, int age) : CPerson(firstName, secondName, lastName), m_countPublications(countPublications), m_post(post), m_age(age) {}
    ~CProfessor() {}
public:
    void ShowData(std::ostream&);
};

#endif