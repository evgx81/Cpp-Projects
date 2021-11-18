#include "fraction.hh"

#include <stdexcept>

int Fraction::gcd(long nominator, unsigned short denominator) {
    //Т.к числитель может быть меньше нуля, возьмем его по модулю
    if (denominator == 0) 
        return std::abs(nominator); 
    else 
        return gcd(denominator, std::abs(nominator) % denominator); 
}


void Fraction::normalizeFraction() {
    int m_gcd = gcd(m_nominator, m_denominator);

    m_nominator /= m_gcd;
    m_denominator /= m_gcd;

}

Fraction::Fraction(long nominator, unsigned short denominator) : m_nominator(nominator), m_denominator(denominator){

    normalizeFraction();

    if(m_denominator == 0)
        throw std::invalid_argument("A fractional part uquels to zero!"); 
}

Fraction Fraction::operator+(const Fraction& val) {
    Fraction m_val;
    if(m_denominator == val.m_denominator) {
        m_val.m_nominator = m_nominator + val.m_nominator;
        m_val.m_denominator = val.m_denominator;
    }
    else {
        m_val.m_nominator = m_nominator * val.m_denominator + val.m_nominator * m_denominator;
        m_val.m_denominator = m_denominator * val.m_denominator;
    }

    m_val.normalizeFraction();
    return m_val;

}

Fraction Fraction::operator-(const Fraction& val) {
    Fraction m_val;
    if(m_denominator == val.m_denominator) {
        m_val.m_nominator = m_nominator - val.m_nominator;
        m_val.m_denominator = val.m_denominator;
    }
    else {
        m_val.m_nominator = m_nominator * val.m_denominator - val.m_nominator * m_denominator;
        m_val.m_denominator = m_denominator * val.m_denominator;
    }

    m_val.normalizeFraction();
    return m_val;

}

Fraction Fraction::operator*(const Fraction& val) {
    Fraction m_val;
    m_val.m_nominator = m_nominator * val.m_nominator;
    m_val.m_denominator = m_denominator * val.m_denominator;
    m_val.normalizeFraction();
    return m_val;

}

bool Fraction::operator==(const Fraction& val) {
    if(m_denominator == val.m_denominator)
        return m_nominator == val.m_nominator ? true : false;
    else 
        return (m_nominator * val.m_denominator) == (m_denominator * val.m_nominator) ? true : false;
}

bool Fraction::operator!=(const Fraction& val) {
    if(m_denominator == val.m_denominator)
        return m_nominator != val.m_nominator ? true : false;
    else 
        return (m_nominator * val.m_denominator) != (m_denominator * val.m_nominator) ? true : false;
}

bool Fraction::operator>(const Fraction& val) {
    if(m_denominator == val.m_denominator)
        return m_nominator > val.m_nominator ? true : false;
    else 
        return (m_nominator * val.m_denominator) > (m_denominator * val.m_nominator) ? true : false;
}

bool Fraction::operator<(const Fraction& val) {
    if(m_denominator == val.m_denominator)
        return m_nominator < val.m_nominator? true : false;
    else 
        return (m_nominator * val.m_denominator) < (m_denominator * val.m_nominator) ? true : false;
}


Fraction& Fraction::operator=(const Fraction& m_val) {
    m_nominator = m_val.m_nominator;
    m_denominator = m_val.m_denominator;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& val) {
    if(val.m_denominator == 1)
        os << val.m_nominator;
    else 
        os << val.m_nominator<< "/" << val.m_denominator;
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& val) {
    std::cout << "Введите числитель дроби: " ;
    is >> val.m_nominator;
    std::cout << "Введите знаменатель дроби: " ;
    is >> val.m_denominator;

    if(val.m_denominator == 0)
        throw std::invalid_argument("A fractional part uquels to zero!"); 

    std::cout << '\n';
    return is;
}
