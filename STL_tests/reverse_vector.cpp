#include <iostream>
#include <algorithm>
#include <vector>

// Вывести число в обратном порядке

std::vector<int> reverseSeq(int n) {
    std::vector<int> ivec;
    for(int i = 1; i <= n; i++){
        ivec.push_back(i);
    }
    std::reverse(ivec.begin(), ivec.end());
    return ivec;
}

int main(){
    int num = 0;
    std::cout << "Введите количество элементов: ";
    std::cin >> num;
    std::vector<int> vec = reverseSeq(num);

    for(int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " "; 
    return 0;
}