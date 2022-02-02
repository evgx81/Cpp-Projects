#include <iostream>
#include <cstring>

using namespace std;


// Пусть даны целое число n, символы s1, s2, ..., sn, среди которых есть двоеточие.
// Получите все символы, расположенные до первого двоеточия включительно.

int main(){
    int n; //Количество символов
    cout << "Введите количество символов: ";
    cin >> n;

    char ch;
    string result = "";

    cout << "Введите символы: ";
    int count = 0; //Количество двоеточий
    for (int i = 1; i < n; ++i){
        cin >> ch;
        if(count != 1)    
                result += ch;
                //result += ch; //Запоминаем символы, которые вводит пользователь
        if(ch == ':')
            count ++;   
    }

     cout << "Нужная строка: " << result << '\n'; 
}