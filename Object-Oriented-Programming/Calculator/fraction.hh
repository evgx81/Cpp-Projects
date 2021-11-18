#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
    long m_nominator; // Целая часть - длинное целое со знаком
    unsigned short m_denominator; // Дробная часть - беззнаковое короткое целое

private:
    // Нахождение наиобщего большего делителя
    int gcd(long, unsigned short);
    // Метод сокращения дроби
    void normalizeFraction();

public:
    // Конструктор по умолчанию
    Fraction() : m_nominator(0), m_denominator(1) {};
    // Конструктор с параметрами
    Fraction(long, unsigned short);

public:

    // Перегруженные арифметические операции
    Fraction operator+ (const Fraction&);
    Fraction operator- (const Fraction&);
    Fraction operator* (const Fraction&);

    // Перегруженные операции сравнения 
    bool operator== (const Fraction&);
    bool operator!= (const Fraction&);
    bool operator> (const Fraction&);
    bool operator< (const Fraction&);

    Fraction& operator= (const Fraction&);

    // Перегруженные операторы << и >> 
    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);
    
};

#endif