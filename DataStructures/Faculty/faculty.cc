#include "faculty.hh"
#include <stdexcept>

double Faculty::averageScore(const std::string& subjectVal, int courseVal)
{
    Course* course = &m_facultyCourses[courseVal-1];
    return course->getAvarageScore(subjectVal);
}

void Faculty::fill(std::ifstream& fin)
{
    while(!fin.eof()) {
        // Сначала в локальную переменную считваем курс
        int courseNumber{};

        fin >> courseNumber;
        fin.ignore();
    
        // Будем осуществлять проверку номера курса, и кидать исключение если считанный курс < 1 и > 6
        // if (courseNumber < 1 || courseNumber > 6)
        // {
        //     throw std::invalid_argument("Неверно заданный номер курса!\n");
        // }

        // Находим курс в массиве курсов
        Course* course = &m_facultyCourses[courseNumber-1];

        // Теперь считываем группу
        int groupNumber{};
        fin >> groupNumber;
        fin.ignore();

        // Проверяем, есть ли такая группа на курсе
        bool groupFlag = course->isGroupInList(groupNumber);

        // Если такой группы не существует, то мы ее создаем и получаем ее указатель
        if(groupFlag == false)
        {
            // Создаем новую группу
            Group newGroup;
            // Задаем новой группе значение группы
            newGroup.setGroup(groupNumber);
            // Добавляем созданную группу в список групп на курсе
            course->addGroup(newGroup);
        }

        // Находим группу в списке групп
        Group* group = course->findGroupByNumber(groupNumber);

        // Считываем студента
        Student* studentGroup = new Student;
        fin >> *studentGroup;

        // Заносим студента
        group->addStudent(studentGroup);
    }
}

std::ostream& operator<<(std::ostream& os, const Faculty& faculty)
{
    for(int i = 0; i < 6; i++)
        os << faculty.m_facultyCourses[i];
    return os;
}