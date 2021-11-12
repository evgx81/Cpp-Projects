#include "group.hh"

bool Group::isSubjectInGroup(const std::string& subject)
{
    // Рассматриваем первый элемент в списке групп
    Student student = *(m_groupStudents.begin());
    return student.isSubjectInStudent(subject);
}

double Group::averageScoreOfGroup(const std::string& subject)
{
    double sum {0};
    // Если данный предмет присутсвует в группе, то считаем сумму оценок по данному предмету
    if(isSubjectInGroup(subject) == true)
    {
        for(List<Student>::iterator student = m_groupStudents.begin(); student != m_groupStudents.end(); student++)
        {
            sum += student->getStudentMark(subject);
        }
    }

    return sum / m_countStudents;
}

void Group::addStudent(Student* student)
{
    // Увеличиваем кол-во студентов в группе
    m_countStudents++;
    // Добавляем студента в группу
    m_groupStudents.addToHead(*student);
}

std::ostream& operator<<(std::ostream& os, const Group& group)
{
    // Выводим список студентов в группе на экран
    for(List<Student>::iterator student = group.m_groupStudents.begin(); student != group.m_groupStudents.end(); student++)
    {
        os << group.m_groupNumber << '\n';
        os << *student;
    }
    return os;
}