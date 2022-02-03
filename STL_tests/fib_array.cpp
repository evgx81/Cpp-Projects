#include <iostream>
#include <cstdint>
#include <array>

static std::array<uint_fast64_t, 100> cache{0, 1}; // cahche[0] = 0; cache[1] = 1; cache... = 0

uint_fast64_t fib(const int n) {
    if(n <= 0)
        return 0;
    
    if (cache[n] == 0)
        cache[n] = fib(n - 1) + fib(n - 2);
    return cache[n];
}

int main() {
    int n{50};
    for(int i = 1; i <= n; i++)
        std::cout << i << ": " << fib(i) << std::endl;
    return 0; 
} 
