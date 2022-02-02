#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

//Рекурсивно считать элементы из файла f и описать функцию comp(), которая
//выводит произведение нечетных отрицательных элементов файла.
        
void comp(const std::string &str){
    int mul = 1;
    int n = 0;
    std::string buf; 
    for(int i = 0; i <= str.length(); i++){
        if(isdigit(str[i]) || str[i] == '-'){
                buf += (str[i]);
        }
        else{
            if(!buf.empty()){
                n = atoi(buf.c_str());

                if(n < 0 && n % 2 != 0)
                    mul *= n;
            }
            buf = "";
        }
    }

    if(mul != 1)
        std::cout << "Произведение нечетных отрицательных элементов файла: " << mul << std::endl;
    else
        std::cout << "В файле нет нечетных отрицательных чисел" << std::endl;

}

int main(){
    std::ifstream file("test.txt", std::ios::in);

    if(!file.is_open()){
        std::cout << "Невозможно открыть файл" << std::endl;
        return 1;
    }

    std::string text;
    while(!file.eof()){
        std::string str;
        getline(file, str); 
        text += str;
        text += ' ';
    }
    comp(text);

    return 0;
}
