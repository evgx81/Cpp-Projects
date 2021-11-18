#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class ComplexNumber {
    double* m_x; // действительная часть
    double* m_y; // комплексная часть

public:
    // Конструктор по умолчанию
    ComplexNumber();
    // Конструктор копирования
    ComplexNumber(const ComplexNumber&);
    // Конструктор с параметрами
    ComplexNumber(const double&, const double&);
    // Деструктор
    ~ComplexNumber();

public:
    // Перегруженные арифметические операции
    ComplexNumber operator+ (const ComplexNumber&);
    ComplexNumber operator- (const ComplexNumber&);
    ComplexNumber operator* (const ComplexNumber&);
    ComplexNumber operator/ (const ComplexNumber&);

    // Перегруженные операции сравнения 
    bool operator== (const ComplexNumber&);
    bool operator!= (const ComplexNumber&);


    // Перегруженный оператор присваивания
    ComplexNumber& operator= (const ComplexNumber&);
    
    // Перегруженные операции >> и <<
    friend std::ostream& operator<<(std::ostream&, const ComplexNumber&);
    friend std::istream& operator>>(std::istream&, const ComplexNumber&);

};

#endif