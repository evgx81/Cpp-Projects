#include <iostream>
#include <cstdlib>

using namespace std;

/*
С	помощью	switch	организовать	выбор	преобразования	целого	числа	(перевод	
в	2,	перевод	8,	перевод	в	16,	можно	воспользоваться	готовыми	функциями).	
Два	целых	числа	вводит	пользователь.

*/


//Запись числа в двоичной системе исчисления
int BinSystem(int num){
    int t = 0; //Искомое число в двоичной системе исчисления 
    int d = 1; //Регулирует разряд
    while(num > 0){
        t += d * (num % 2);
        num = num / 2;
        d = d * 10;
    }
    return t;
}

int main(){
    int number1, number2;
    int system;
    

    cout << "Введите первое число: ";
    cin >> number1;

    cout << "Введете второе число: ";
    cin >> number2;

    cout << '\n';

    cout << "Выберете систему исчисления(2, 8, 16-ныe системы исчисления): ";
    cin >> system;

    cout << '\n';

    switch(system){
    case 2:
        cout << "Число " << number1 << " в двоичной системе исчисления: " << BinSystem(number1) << endl;
        cout << "Число " << number2 << " в двоичной системе исчисления: " << BinSystem(number2) << endl;
        break;
    case 8:
        cout << "Число " << number1 << " в восьмеричной системе исчисления: " << oct << number1 << endl;
        cout << "Число " << number2 << " в восьмеричной системе исчисления: " << oct << number2 << endl;
        break;
    case 16:
        cout << "Число " << number1 << " в шестнадцатеричной системе исчисления: " << hex << number1 << endl;
        cout << "Число " << number2 << " в шестнадцатеричной системе исчисления: " << hex << number2 << endl;
        break;
    default: 
        cout << "Вы ввели неверную систему исчесления." << endl;                
   }

    return 0;
}

