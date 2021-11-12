#include "student.hh"

int Student::getStudentMark(const std::string& subject)
{
    int mark{};
    for(int i = 0; i < 5; i++)
    {
        if(m_results[i].getSubjectName() == subject)
            mark = m_results[i].getMark();
    }
    return mark;
}

bool Student::isSubjectInStudent(const std::string& subject)
{
    // Предположим, что такого предмета у студента в группе нет
    bool subjectFlag = false;
    for(int i = 0; i < 5; i++)
    {
        if(m_results[i].getSubjectName() == subject)
            subjectFlag = true;
    }
    return subjectFlag;
}

std::istream& operator>>(std::istream& fin, Student& student)
{
    getline(fin, student.m_fio, '\n');
    fin >> student.m_form;
    for(int i = 0; i < 5; i++){
        fin.ignore(); 
        fin >> student.m_results[i];
    }
    fin.ignore();
    fin.ignore();

    return fin;
}

std::ostream& operator<<(std::ostream& os, const Student& student)
{
    os << student.m_fio << '\n';
    os << student.m_form << '\n';
    for(int i = 0; i < 5; i++) 
    {
        os << student.m_results[i];
    }
    os << '\n';
    return os;
}