#ifndef H_PERSON
#define H_PERSON

#include <string>
#include <iostream>

class CPerson 
{
protected:
    std::string m_firstName;
    std::string m_secondName;
    std::string m_lastName;

public:
    CPerson(std::string firstName, std::string secondName, std::string lastName) : m_firstName(firstName), m_secondName(secondName), m_lastName(lastName) {};
    virtual ~CPerson() {}
public:
    virtual void ShowData(std::ostream&) ;
};
#endif