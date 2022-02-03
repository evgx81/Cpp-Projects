#include <iostream>

template <long N>
class Factorial {
public:
    enum {
        Argument = N
    };
    static long value();
};

template <long N>
long Factorial<N>::value() {
    return N * Factorial<N-1>::value();
}

template <>
long Factorial<0>::value() {
    return 1;
}

int main()
{
    Factorial<500> fact;
    std::cout << "Factorial for argument " << fact.Argument << " is " << fact.value() << std::endl;
}