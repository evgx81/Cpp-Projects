#include "myint.h"

MyInt fact(const MyInt& n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main() {
    std::cout << fact(2) << std::endl;
    return 0;
}