#include <iostream>
#include <fstream>
#include <cctype>
#include <cstring>
#include <string>
using namespace std;
//Пусть дан текстовый файл. Подсчитайте кол-во пустых строк.

int main(){
    // Наиболее часто применяются классы ifstream для чтения, ofstream для записи и fstream для модификации файлов.
    ifstream file("txt_test.txt",  ios::in);

    if(!file.is_open()){
        cout << "Невозможно открыть файл!" << endl;
        // возврат ошибки при открытие
        return 1;
    }

    int count = 0;
    string line;
    while(!file.eof()){

        getline(file, line);
        int count_alpha = 0;
        int count_space = 0;

        for(int i = 0; i < line.size(); i++){

            if(isgraph(line[i])){
                count_alpha++;
            }

            if(isspace(line[i])){
                count_space++;
                
            }

        }

        if(count_alpha <= 0 || line.empty() || count_space == line.length())
            count++; 
    }
    cout << "Количество пустых строк: " << count << endl;
        
    return 0;
}