#include <iostream>

using namespace std;

void print(char values[], int n) {
    for (int i = 0; i < n; i++) {
        cout << values[i] << ' ';
    }
    cout << '\n';
}

int partition(char arr[], int l, int r, char v) {
    int i = l;
    int j = r;
    while (i <= j) 
    {
        while (arr[i] < v) {
            i++;
        }
        while (arr[j] > v) {
            j--;
        }
        if (i >= j) {
            break;
        }
        swap(arr[i++], arr[j--]);
    }
    return j;
}

void quickSortImpl(char nuts[], char bolts[], int l, int r) {
    if (l < r) {
        // Выберем последний элемент массива bolts как основной
        // Относительно этого элемента сортируем массив nuts так,  
        // что все элементы меньшие bolts[r] будут левее, а большие правее
        int q = partition(nuts, l, r, bolts[r]);
        // q - индекс гайки, соотвествующей индексу болта r
        // Дальше относительно индекса q сортируем массив bolts
        // Такой же алгоритм для каждого подмассива
        partition(bolts, l, r, nuts[q]);
        quickSortImpl(nuts, bolts, l, q);
        quickSortImpl(nuts, bolts, q + 1, r);
    }
}

void match(char nuts[], char bolts[], int N) 
{
    quickSortImpl(nuts, bolts, 0, N-1);
}


void nutsAndBoltsMatching() {
    const int N = 7;
    char nuts[] = {'!', '@', '#', '$', '%', '^', '&'};
    char bolts[] = {'$', '!', '%', '&', '^', '@', '#'};

    match(nuts, bolts, N);

    // Выводим 2 отсортированных массива
    cout <<"Pairs of nuts and bolts are : \n";
    print(nuts, N);
    print(bolts, N);
}

int main() {
    nutsAndBoltsMatching();
    return 0;
}