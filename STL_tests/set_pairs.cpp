#include <iostream>
#include <fstream>
#include <vector>

// Рекурсивная функция печати всех в подмножестве

void printAllSubsetsRec(int arr[], int n, std::vector<int> v, int sum)
{
    if (sum == 0) {
        for (auto x : v)
            std::cout << x << " ";
        std::cout << '\n';
        return;
    }
    else if (n == 0)
        return;
    else{
        printAllSubsetsRec(arr, n - 1, v, sum);
        v.push_back(arr[n - 1]);
        printAllSubsetsRec(arr, n - 1, v, sum - arr[n - 1]);
    }
}
  

int main(){
    std::ifstream fin("TestFile.txt", std::ios::in);

    if (!fin.is_open()) 
        return 1;

    int N{0};
    fin >> N;

    int* data = new int[N];
    for(int i = 0; i < N; i++)
        fin >> data[i];        

    int X{0};
    fin >> X;
    fin.close();

    // Вектор v будет хранить подмножество
    std::vector<int> v;
    printAllSubsetsRec(data, N, v, X);
    delete[] data;
    return 0;
}
