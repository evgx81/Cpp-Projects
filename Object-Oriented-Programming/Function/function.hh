#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

class Function
{
protected:
    double m_a;
    double m_b;
public:
    Function(double a, double b) : m_a(a), m_b(b) {}
public:
    // Чисто виртуальная функция вычисления значения функции
    virtual double calculateFunction() = 0;
    // Вывод значения функции
    virtual std::string showData() = 0;  
};

#endif