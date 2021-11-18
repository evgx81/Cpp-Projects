#include "calculator.hh"

Calculator::Calculator(Fraction frac1, Fraction frac2, char operation) : m_frac1(frac1), m_frac2(frac2), m_result(0, 1), m_operation(operation), m_compare(true) {
    if(m_operation == '+' || m_operation == '-' || m_operation == '*')
        Calculate(frac1, frac2, operation);
    else
        Compare(frac1, frac2, operation);
}

void Calculator::Calculate(Fraction a, Fraction b, char operation) {
    if (operation == '+')
        m_result = a + b;
    else if (operation == '-') 
        m_result = a - b;
    else if (operation == '*')
        m_result = a * b;
} 

void Calculator::Compare(Fraction a, Fraction b, char operation) {
    if (operation == '=')
        m_compare = a == b;
    else if (operation == '!') 
        m_compare = a != b;
    else if (operation == '>') 
        m_compare = a > b;
    else if (operation == '<') 
        m_compare = a < b;
}

void Calculator::printResult(std::ostream& os) {
    if(m_operation == '+' || m_operation == '-' || m_operation == '*')
        os << m_result;
    else if(m_operation == '>') {
        if(m_compare == true)
            os << "Дробь " << m_frac1 << " больше " << m_frac2;
        else
            os << "Дробь " << m_frac2 << " больше " << m_frac1;
    }
    else if(m_operation == '<') {
        if(m_compare == true)
            os << "Дробь " << m_frac1 << " меньше " << m_frac2;
        else
            os << "Дробь " << m_frac2 << " меньше " << m_frac1;
    }
    else 
        os << std::boolalpha << m_compare;
}