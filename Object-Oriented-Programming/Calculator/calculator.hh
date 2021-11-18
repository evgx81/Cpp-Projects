#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "fraction.hh"

class Calculator {
    // Внутренний объекты
    Fraction m_frac1;
    Fraction m_frac2;
    Fraction m_result;
    char m_operation;
    bool m_compare;

    void Calculate(Fraction, Fraction, char);
    void Compare(Fraction, Fraction, char);
public:
    // Конструктор
    Calculator(Fraction, Fraction, char);
public:
    
    // Печатаем результат
    void printResult(std::ostream& os);
};

#endif