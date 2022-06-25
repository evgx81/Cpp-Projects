#include <iostream>
#include <vector>

void accommodations(std::vector<int>& d, int pos, int N, int M) {
    if (pos == N) {
        for (int i = 0; i < N; ++i)
            std::cout << d[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int k = 1; k <= M; ++k) {
        d.push_back(k);
        accommodations(d, pos + 1, N, M);
        d.pop_back();
    }
}

/*
Пример: вывести все расстановки
    N=3 - кол-во позиций, M=2 - кол-во чисел
1 1 1 | 2 1 1
1 1 2 | 2 1 2
1 2 1 | 2 2 1
1 2 2 | 2 2 2
*/

void permutations(std::vector<int>& d, int pos, int N, std::vector<bool>& used) {
    if (pos == N) {
        for (int i = 0; i < N; ++i)
            std::cout << d[i] << ' ';
        std::cout << '\n';
        return;
    }
    for (int k = 1; k <= N; ++k) {
        if (used[k-1] == false) {
            d.push_back(k);
            used[k-1] = true;
            permutations(d, pos + 1, N, used);
            d.pop_back();
            used[k-1] = false;
        }
    }
}

/*
Пример: вывести все расстановки
        N=3 - кол-во позиций, M=2 - кол-во чисел
1 1 1 | 2 1 1
1 1 2 | 2 1 2
1 2 1 | 2 2 1
1 2 2 | 2 2 2
*/

void combinataions(std::vector<int>& d, int i, int N, int M)
{
    if (M == d.size())
    {
        for (int j = 0; j < M; ++j)
            std::cout << d[j] << ' ';
        std::cout << '\n';
        return; 
    }

    for (int k = i; k <= N; ++k)
    {
        d.push_back(k);
        combinataions(d, k + 1, N, M);
        d.pop_back();
    }
}

/*
Пример: вывести все сочетания
        N=3 - кол-во позиций, M=2 - кол-во чисел
1 2
1 3
2 3
*/

int main()
{
    // M - количество элементов в одной группе
    int M = 2;
    // N - количество возможных элементов
    int N = 3;
    std::vector<int> arr;

    std::cout << "Accomodations: " << '\n';
    accommodations(arr, 0, N, M);
    std::cout << '\n';

    std::cout << "Permutations: " << '\n';
    std::vector<bool> used(N, false);
    permutations(arr, 0, N, used);
    std::cout << '\n';

    std::cout << "Combinations: " << '\n';
    combinataions(arr, 1, N, M);
    std::cout << '\n';
    return 0;
}