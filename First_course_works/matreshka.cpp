#include <iostream>

void matreshka(int& n) {
    if(n == 0)
        std::cout << "Finish\n";
    else{ 
        std::cout << "Top side of matreshka " << n << std::endl;
        auto next = n - 1;
        matreshka(next);
        std::cout << "Bottom side of matreshka " << n << std::endl;
    }
}

int main()
{
    int x = 10;
    matreshka(x);

    return 0;
}