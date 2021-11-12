#include "cell.hh"

bool Cell::operator==(const Cell& cell)
{
    return (m_x == cell.m_x) && (m_y == cell.m_y);
}

std::ostream& operator<<(std::ostream& os, const Cell& cell)
{
    std::cout << '{';
    os << cell.m_x;
    std::cout << ", ";
    os << cell.m_y;
    std::cout << '}';
    return os; 
}

std::istream& operator>>(std::istream& is, Cell& cell)
{
    std::cout << "Введите координату x: ";
    is >> cell.m_x;
    std::cout << "Введите координату y: ";
    is >> cell.m_y;
    std::cout << '\n';

    if(cell.m_x < 0 || cell.m_x > 9)
        throw std::invalid_argument("Значение координаты 'x' выходит за пределы массива!");
    
    if(cell.m_y < 0 || cell.m_y > 9)
        throw std::invalid_argument("Значение координаты 'y' выходит за пределы массива!");

    return is;
}