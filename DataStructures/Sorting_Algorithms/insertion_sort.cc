#include <iostream>
#include <vector>

void InsertionSort(std::vector<int>& arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        int v = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > v)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
    }
}

int main()
{
    std::vector<int> arr{100, 19, -98, 17, -66, -15, 0, -3, 20, 41};
    InsertionSort(arr);
    std::cout << "Сортировка вставками: ";
    for (auto elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
    return 0;
}