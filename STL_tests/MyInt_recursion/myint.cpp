#include "myint.h"

MyInt::MyInt() : m_val{0} {
    std::cout << "Contructor" << std::endl;
}

MyInt::MyInt(int val) : m_val{val} {
    std::cout << "Contructor" << std::endl;
}

MyInt::~MyInt() {
    std::cout << "Destructor" << std::endl;
}

MyInt::MyInt(const MyInt& copy) : m_val{copy.m_val} {
    std::cout << "Copy Contructor" << std::endl;
}

MyInt MyInt::operator+(const MyInt& val) const {
    return MyInt(m_val + val.m_val);
}

MyInt MyInt::operator+(const int& val) const {
    return MyInt(m_val + val);
}

MyInt MyInt::operator-(const MyInt& val) const {
    return MyInt(m_val - val.m_val);
}

MyInt MyInt::operator-(const int& val) const {
    return MyInt(m_val - val);
}

MyInt MyInt::operator*(const MyInt& val) const {
    return MyInt(m_val * val.m_val);
}

MyInt MyInt::operator*(const int& val) const {
    return MyInt(m_val * val);
}

bool MyInt::operator==(const MyInt& val) const {
    return m_val == val.m_val;
}

bool MyInt::operator==(const int& val) const {
    return m_val == val;
}

std::ostream& operator<<(std::ostream& out, const MyInt& val) {
    out << val.m_val;
    return out;
}

MyInt::MyInt(MyInt&& val) : m_val(val.m_val) {
    std::cout << "Move constructor" << std::endl;
}
