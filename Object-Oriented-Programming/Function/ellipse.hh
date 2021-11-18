#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "function.hh"

class Ellipse : public Function
{
private:
    double m_x;    
public:
    Ellipse(double a, double b, double x = 0) : Function(a, b), m_x{x} {}
public:
    // Вычисление y
    double calculateFunction();
    // Вывод значения y
    std::string showData();
public:
    void setX(double);
public:
    // Индикатор кол-ва корней
    int analyzeData();
};

#endif