#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <stdexcept>

// Создаем структуру, которая будет определяет клетку в лабиринте
struct Cell
{
    int m_x;
    int m_y;

    Cell(int x = 0, int y = 0) : m_x{x}, m_y{y} {}

    Cell(const Cell& pos)
    {
        m_x = pos.m_x;
        m_y = pos.m_y;
    }

    bool operator==(const Cell&);
    friend std::ostream& operator<<(std::ostream&, const Cell&);
    friend std::istream& operator>>(std::istream&, Cell&);

};

#endif