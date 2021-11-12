#include "subject.hh"

std::istream& operator>>(std::istream& fin, Subject& subject)
{
    fin >> subject.m_name >> subject.m_mark;
    return fin;
}

std::ostream& operator<<(std::ostream& os, const Subject& subject)
{
    os << subject.m_name << ": " << subject.m_mark << '\n';
    return os;
}