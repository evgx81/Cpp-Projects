#include <iostream>
#include <vector>

void BubbleSort(std::vector<int>& arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] > arr[j+1])
                std::swap(arr[j], arr[j+1]);
        }
    }
}

int main()
{
    std::vector<int> arr{100, 19, -98, 17, -66, -15, 0, -3, 20, 41};
    BubbleSort(arr);
    std::cout << "Сортировка пузырьком: ";
    for (auto elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
    return 0;
}



