#include <iostream>
#include <cmath>

bool isPerfectSquare(long int sq){
    long int root = round(sqrt(sq));
    if(root * root == sq)
        return true;
    else 
        return false;
}

long int findNextSquare(long int n){
    long int res = round((sqrt(n)));
    if(isPerfectSquare(n)){
        res = res + 1;
        if(isPerfectSquare(n)){
            n = res * res;
            return n;
        }
    }
    else 
        return -1;
}

int main(){
    long int h;
    std::cin>>h;
    std::cout << isPerfectSquare(h) << std::endl;
    std::cout << findNextSquare(h) << std::endl;
    return 0;
}