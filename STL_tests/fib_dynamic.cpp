#include <iostream>
#include <cstdint>
#include <array>


uint_fast64_t fib(const int n) {
    if(n <= 0)
        return 0;

    uint_fast64_t Fib[n + 1];
    Fib[0] = 0;
    Fib[1] = 1;

    for (int i{2}; i <= n; ++i)
        Fib[i] = Fib[i - 1] + Fib[i - 2];

    return Fib[n];
}

int main() {
    constexpr int n{50};
    for(int i = 1; i <= n; i++)
        std::cout << i << ": " << fib(i) << std::endl;
    return 0; 
} 