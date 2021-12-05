#include "my_utils.h"

uint_fast64_t factRecursive(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    return n * factRecursive(n - 1);
}

uint_fast64_t factCycle(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    
    uint_fast64_t mul{1};
    for(int i{1}; i <= n; ++i) {
        mul *= i;
    }
    return mul;
}