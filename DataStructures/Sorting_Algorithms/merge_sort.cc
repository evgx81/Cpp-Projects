#include <iostream>
#include <vector>

void merge (std::vector<int>& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    std::vector<int> temp1(n1);
    std::vector<int> temp2(n2);

    for (int i = 0; i < n1; i++) 
        temp1[i] = arr[l + i];

    for (int i = 0;i < n2;i++) 
        temp2[i] = arr[mid + i + 1];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (temp1[i] < temp2[j]) 
        {
            arr[k] = temp1[i];
            k++;
            i++;
        }
        else {
            arr[k] = temp2[j];
            k++;
            j++;
        }
    }

    while (i < n1) 
    {
        arr[k] = temp1[i];
        k++;
        i++;
    }
    while (i < n2) 
    {
        arr[k] = temp2[i];
        k++;
        i++;
    }
    temp1.clear();
    temp2.clear();
}

void mergeSort(std::vector<int>& arr, int l, int r)
{
    if (l < r)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void MergeSort(std::vector<int>& arr)
{
    mergeSort(arr, 0, arr.size()-1);
}

int main()
{
    std::vector<int> arr{ 12, 11, 13, 5, 6, 7 };
    MergeSort(arr);
    std::cout << "Сортировка слиянием: ";
    for (auto elem : arr)
        std::cout << elem << ' ';
    std::cout << '\n';
    return 0;
}