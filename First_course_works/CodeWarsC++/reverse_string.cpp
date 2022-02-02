#include <iostream>

int main(){
    std::string str;
    std::cout << "Введите строку: ";
    getline(std::cin, str);

    for(int i = 0; i < str.length() / 2; i++){
      char temp = str[i];
      str[i] = str[str.length() - i - 1];
      str[str.length() - i - 1] = temp;

    }

    std::cout << "Перевернутая строка: " << str << std::endl;

    return 0;
} 