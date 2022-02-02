#include <iostream>
#include <cmath>

const double epsilon = 0.0001;
double recursion(const int& k, const double& x, double y0, double y1){

    if(fabs(y0 - y1) < epsilon) 
        return y1;
    else{
        y0 = y1;
        y1 = y0 + ((x / pow(y0, k - 1) - y0) / k);
        return recursion(k, x, y0, y1);
    }    
}

// Рекурсивное вычисление степени корня k

int main(){
    int k{0};
    std::cout << "Введите степень корня k: ";
    std::cin >> k;

    if(k < 1){
        std::cout << "Неверный ввод данных!" << std::endl;
        return -1;
    }

    double x{0.0};
    std::cout<< "Введите значение x: ";
    std::cin >> x;
    if(x < 0){
        std::cout << "Неверный ввод данных!" << std::endl;
        return -1;
    }

    double y0{1.0};
    double y1 = y0 + ((x / pow(double(y0), double(k - 1)) - y0) / k);
    std::cout << "\n";

    bool flag = true;
    while (flag) {
        y0 = y1;
        y1 = y0 + ((x / pow(double(y0), double(k - 1)) - y0) / k);

        if(fabs(y0 - y1) < epsilon)
            flag = false;
    }

    std::cout << "\n";


    std::cout << "Проверка: " << pow(x, 1 / double(k)) << std::endl;

    std::cout << "Первый способ: " << y1 << std::endl;

    double y3{1.0};
    double y4 = y3 + ((x / pow(y3, k - 1) - y3) / k);

    std::cout << "Второй способ: " << recursion(k, x, y3, y4);
    return 0;
}