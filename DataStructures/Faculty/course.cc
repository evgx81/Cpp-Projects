#include "course.hh"

double Course::getAvarageScore(const std::string& subject)
{  
    // Хранит средний балл каждой группы, у которой есть заданный предмет
    double avgScore{};
    // Хранит количество таких групп
    int m_groups{};
    for(List<Group>::iterator group = m_courseGroups.begin(); group != m_courseGroups.end(); group++)
    {
        avgScore += group->averageScoreOfGroup(subject);
        if(group->isSubjectInGroup(subject) == true) 
            m_groups++;
    }
    return avgScore / m_groups;
}

bool Course::isGroupInList(int group)
{
    // Предположим, что изначально такой группы нет
    bool groupFlag = false;
    // Просматриваем список групп
    for (List<Group>::iterator iter = m_courseGroups.begin(); groupFlag == true && iter != m_courseGroups.end(); iter++)
    {
        // Если мы нашли такую группу
        if(iter->getGroupNumber() == group)
            groupFlag = true;
    }
    return groupFlag;
}

void Course::addGroup(const Group& newGroup)
{
    // Увеличиваем кол-во групп на курсе
    m_countGroups++;
    // Добавляем в список групп
    m_courseGroups.addToHead(newGroup);
}

Group* Course::findGroupByNumber(int group) 
{
    // Ищем нужную группу по номеру группы
    auto iter = m_courseGroups.begin();
    while(iter != m_courseGroups.end() && iter->getGroupNumber() != group)
        iter++;
    return (&(*iter));
}

std::ostream& operator<<(std::ostream& os, const Course& course)
{
    // Выводим список групп в курсе на экран
    for(List<Group>::iterator group = course.m_courseGroups.begin(); group != course.m_courseGroups.end(); group++)
    {
        os << course.m_courseNumber << '\n';
        os << *group;
    }
    return os;
}

