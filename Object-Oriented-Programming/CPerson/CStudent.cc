#include "CStudent.hh"

#include <iostream>

void CStudent::ShowData(std::ostream& os) {
    os << "Имя: " << m_firstName << '\n';
    os << "Фамилия: " << m_secondName << '\n';
    os << "Отчество: " << m_lastName << '\n';
    os << "Средний балл: " << m_avScore << '\n';
    os << "Номер группы: " << m_course << '\n';
    os << '\n';
}