#include <iostream>

class Foo {

public:
    Foo() { std::cout << "Конструктор класса Foo\n"; }
    ~Foo() { std::cout << "Виртуальный деструктор класса Foo\n";}
};

class Bar : public Foo {

public:
    Bar() { std::cout << "Конструктор класса Bar\n"; }
    ~Bar() { std::cout << "Деструктор класса Bar\n";}
};

int main()
{   
    Foo* foo = new Bar;
    delete foo;
    return 0; 
}
