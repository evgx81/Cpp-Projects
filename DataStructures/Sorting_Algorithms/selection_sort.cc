#include <iostream>
#include <vector>

void SelectionSort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        int min = i;
        for (int j = i; j < arr.size(); ++j)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        std::swap(arr[min], arr[i]);
    }
}

int main()
{
    std::vector<int> arr{100, 19, -98, 17, -66, -15, 0, -3, 20, 41};
    SelectionSort(arr);
    std::cout << "Сортировка выбором: ";
    for (auto elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
    return 0;
}