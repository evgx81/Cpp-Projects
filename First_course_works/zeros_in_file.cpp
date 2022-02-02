#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream file("digit_test.txt", ios::in);

    if(!file.is_open()){
        cout << "Невозможно открыть файл" << endl;
        return 1;
    }

    int count_even = 0;
    int count_odd = 0;
    
    string str;

    while(!file.eof()){
        getline(file, str);
        for(int i = 0; i < str.size(); i++){
            if(i % 2 == 0 && str[i] == '0')
                count_even++;

            if(i % 2 != 0 && str[i] == '0')
                count_odd++;    
        }
    }

    if(count_even > count_odd)
        cout << "Больше нулей на четных позициях" << endl;

    if(count_even < count_odd)
        cout << "Больше нулей на нечетных позициях" << endl;

    if(count_even == count_odd)
        cout << "Кол-во нулей на нечетных позициях равно кол-ву нулей на четных позициях" << endl;

    return 0;    
}