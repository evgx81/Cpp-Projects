#include <iostream>
#include <cmath>

// Рекурсивное вычисление интеграла

double integral(const int& n, const double& x){
    const double PI = 3.1415;
    if(n == 0)
        return x;
    else if(n == 1)
        return log(tan(PI / 4) + (1/2)*x);
    else
        return sin(x)/((n - 1) * (pow(cos(x), n - 1))) + ((n - 2)/(n - 1)) * integral(n - 2, x);
}

int main(){
    int n{0};
    std::cout << "Введите число n: ";
    std::cin >> n;

    if(n < 0){
        std::cout << "Ошибка ввода данных";
        return 1;
    }

    double b{0};
    std::cout << "Введите значение b: ";
    std::cin >> b;

    double a{0};
    std::cout << "Введите значение a: ";
    std::cin >> a;

    if(a > b){
        std::cout << "Ошибка ввода данных";
        return 1;
    }

    std::cout << "Значение интеграла при n = " << n << ", b = " << b << " и a = " << a << " равно: " << integral(n, b) - integral(n, a) << std::endl;
    return 0;
}