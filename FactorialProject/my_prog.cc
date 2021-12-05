#include <iostream>

#include "my_utils.h"

int main()
{
    int n{};
    std::cout << "Enter a number: ";
    std::cin >> n;
    std::cout << "Factorial of " << n << " is: " << factCycle(n) << '\n';

    return EXIT_SUCCESS;
}
