#include "complex.hh"

ComplexNumber::ComplexNumber() {
    m_x = new double{0};
    m_y = new double{0};
}

ComplexNumber::ComplexNumber(const ComplexNumber& val) {
    m_x = new double{*val.m_x};
    m_y = new double{*val.m_y};
}

ComplexNumber::ComplexNumber(const double& x, const double& y) {
    m_x = new double{x};
    m_y = new double{y};
}

ComplexNumber::~ComplexNumber() {
    delete m_x;
    delete m_y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& m_val) {
    ComplexNumber val;
    *val.m_x = *m_x + *m_val.m_x;
    *val.m_y = *m_y + *m_val.m_y;
    return val;

}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& m_val) {
    ComplexNumber val;
    *val.m_x = *m_x - *m_val.m_x;
    *val.m_y = *m_y - *m_val.m_y;    
    return val;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& m_val) {
    ComplexNumber val;
    *val.m_x = (*m_x) * (*m_val.m_x) - (*m_y) * (*m_val.m_y);
    *val.m_y = (*m_x) * (*m_val.m_y) + (*m_y) * (*m_val.m_x);
    return val;
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& m_val) {
    ComplexNumber val;
    *val.m_x = ((*m_x) * (*m_val.m_x) + (*m_y) * (*m_val.m_y)) / ((*m_val.m_x) * (*m_val.m_x) + (*m_val.m_y) * (*m_val.m_y));
    *val.m_y = ((*m_val.m_x) * (*m_y) - (*m_val.m_y) * (*m_x)) / ((*m_val.m_x) * (*m_val.m_x) + (*m_val.m_y) * (*m_val.m_y));

    if (((*m_val.m_x) * (*m_val.m_x) + (*m_val.m_y) * (*m_val.m_y)) == 0)
        throw -1;
    return val;
}

bool ComplexNumber::operator==(const ComplexNumber& m_val) {
    return (*m_x == *m_val.m_x && *m_y == *m_val.m_y) ? true : false;
}

bool ComplexNumber::operator!=(const ComplexNumber& m_val) {
    return (*m_x != *m_val.m_x || *m_y != *m_val.m_y) ? true : false;
}

ComplexNumber& ComplexNumber::operator=(const ComplexNumber& m_val) {
    *m_x = *m_val.m_x;
    *m_y = *m_val.m_y;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ComplexNumber& val) {
    if(*val.m_y < 0){
         os << *val.m_x << " + (" << *val.m_y << ")" << "*i";
    }
    else {
        os << *val.m_x << " + " << *val.m_y << "*i";
    }
    return os;  
}

std::istream& operator>>(std::istream& is, const ComplexNumber& val) {
    std::cout << "Введите действительную часть: "; 
    is >> *val.m_x ;
    std::cout << "Введите мнимую часть: ";
    is >> *val.m_y;
    std::cout << '\n';
    return is;  
}


