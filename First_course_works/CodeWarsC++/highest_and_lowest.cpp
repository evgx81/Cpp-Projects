#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

void highAndLow(const std::string& numbers){
    std::vector<char> arr_plus;
    std::vector<char> arr_minus;
    for(int i = 0; i < numbers.length(); i++){

        for(int i = 0; i < numbers.length(); i++){
            while(numbers[i] == '-' && isdigit(numbers[i+1]))
                arr_minus.push_back(numbers);
            int j = i;
            while (!isspace(numbers[j]) && j != numbers.size())
                ++j;
            if (i != j) {
                arr_plus.push_back(numbers.substr(i, j - i));
                i = j;
        
            }
        }
    
    for(int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
}

int main(){
    std::string ex = "8 3 -5 42 -1 0 0 -9 4 7 4 -4";
    highAndLow(ex);
    return 0;
}