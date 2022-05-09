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
    // std::vector<int> arr{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // std::vector<int> arr{5, 3, 1, 9, 8, 2, 4, 7};
    std::vector<int> arr{100, 19, -98, 17, -66, -15, 0, -3, 20, 41};
    BubbleSort(arr);
    for (auto elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
    return 0;
}