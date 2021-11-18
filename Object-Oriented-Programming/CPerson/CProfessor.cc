#include "CProfessor.hh"

#include <iostream>

void CProfessor::ShowData(std::ostream& os) {
    os << "Имя: " << m_firstName << '\n';
    os << "Фамилия: " << m_secondName << '\n';
    os << "Отчество: " << m_lastName << '\n';
    os << "Количество публикаций: " << m_countPublications <<'\n';
    os << "Должность: ";
    switch(m_post) 
    {
        case Lecturer:
            os << "Преподаватель\n";
            break;
        case Senior_lecturer:
            os << "Старший преподаватель\n";
            break;
        case Docent:
            os << "Доцент\n";
            break;
        case Professor:
            os << "Профессор\n";
            break;
        default:
            os << "Неверные данные о профессии!\n"; 
    };
    os << "Возраст: " << m_age << '\n';
    os << '\n';
}