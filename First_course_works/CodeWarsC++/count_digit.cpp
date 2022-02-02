#include <iostream>
//using namespace std;

class CountDig
{
    int n;
    int d;
public:
    CountDig(int input_n, int input_d){
        n = input_n;
        d = input_d;
    }
    static int nbDig(int n, int d);
};

int CountDig::nbDig(int n, int d){
    long int square = 0;
    int count = 0;
    if(d == 0)
        count = 1; 
    for(int i = 0; i <= n; i++){

        square = i * i;

            while(square > 0){
                if(square % 10 == d)
                    count++;
                square /= 10;
            }
    }

    return count;
}

int main(){

    CountDig object(10, 0);

    std::cout << std::endl;

    std::cout << object.nbDig(5750, 0) << std::endl;

    return 0;
}