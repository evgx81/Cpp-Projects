#include <iostream>
#include <vector>

long fibonacci(const int& n) {
    if (n == 0 || n == 1)
        return 1;  
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

long hash_func(std::vector<long> values, const int& n){
    if (n == 0 || n == 1){
        return 1;
    }
    else
        return fibonacci(values[n - 2]) + fibonacci(values[n - 1]);
}

int main()
{
    std::vector<long> fibs;
    fibs.reserve(1);

    for (int i = 0; i < 1; ++i) 
        fibs.push_back(fibonacci(i));
    
    for (auto elem : fibs) {
        std::cout << elem << std::endl;
    }
}
