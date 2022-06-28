#include <iostream>
#include <vector>

void CocktailSort(std::vector<int>& arr)
{
    int l = 1;
    int r = arr.size() - 1;
    while (l <= r)
    {
        for (int i = l; i <= r; i++)
        {
            if (arr[i-1] > arr[i])
                std::swap(arr[i-1], arr[i]);
        }
        r--;
        for (int i = r; i >= l; i--)
        {
            if (arr[i] < arr[i-1])
                std::swap(arr[i], arr[i-1]);
        }
        l++;
    }
}

int main()
{
    std::vector<int> arr{100, 19, -98, 17, -66, -15, 0, -3, 20, 41};
    CocktailSort(arr);
    std::cout << "Шейкерная сортировка: ";
    for (auto elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
    return 0;
}