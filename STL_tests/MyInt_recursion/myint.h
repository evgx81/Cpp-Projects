#include <iostream>

class MyInt {
    int m_val;

public:
    MyInt();
    MyInt(int);
    ~MyInt();
    MyInt(const MyInt&);

    MyInt(MyInt&&);

    MyInt operator+(const MyInt&) const;
    MyInt operator+(const int&) const;
    
    MyInt operator-(const MyInt&) const;
    MyInt operator-(const int&) const;
    
    MyInt operator*(const MyInt&) const;
    MyInt operator*(const int&) const;
    
    bool operator==(const MyInt&) const;
    bool operator==(const int&) const;
    friend std::ostream& operator<<(std::ostream&, const MyInt&);
};