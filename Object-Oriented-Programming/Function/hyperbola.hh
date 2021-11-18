#ifndef HYPERBOLA_H
#define HYPERBOLA_H

#include "function.hh"

class Hyperbola : public Function
{
private:
    double m_x;
public:
    Hyperbola(double a, double b, double x = 0) : Function(a, b), m_x{x} {}
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