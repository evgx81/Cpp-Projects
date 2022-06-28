#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int l, int r)
{
    int p = arr[l];
    int i = l + 1;
    int j = r;
    while(i <= j)
    {
        while (arr[i] < p)
            i++;
        while (arr[j] > p)
            j--;
        if (i <= j)
        {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    };
    std::swap(arr[l], arr[j]);
    return j;
}

void sort(std::vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int s = partition(arr, l, r);
        sort(arr, l, s-1);
        sort(arr, s+1, r);
    }
}

void QuickSort(std::vector<int>& arr)
{
    sort(arr, 0, arr.size()-1);
}

int main()
{
    std::vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    QuickSort(arr);
    std::cout << "Быстрая сортировка: ";
    for (auto elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
    return 0;
}