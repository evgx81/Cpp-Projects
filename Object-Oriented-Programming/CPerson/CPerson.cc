#include "CPerson.hh"

#include <iostream>

void CPerson::ShowData(std::ostream& os) 
{
    os << "Имя: " << m_firstName << '\n';
    os << "Фамилия: " << m_secondName << '\n';
    os << "Отчество: " << m_lastName << '\n';
    os << '\n';
}