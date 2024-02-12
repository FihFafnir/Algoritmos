#include <bits/stdc++.h>

using namespace std;

void swap(int& first, int& second) {
    int tmp = first;
    first = second;
    second = tmp;
}

template <size_t S>
void printArr(int (&arr)[S], int end = S) {
    cout << "[" << arr[0];
    for (int i = 1; i < end; i++)
        cout << ", " << arr[i];
    cout << "]" << endl;
}

template <size_t S>
void insertionSort(int (&arr)[S]) {
    int i, j, tmp;
    for (i = 0; i < S; i++, arr[j] = tmp)
        for (tmp = arr[i], j = i; j > 0 && tmp < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
}

int main(int argc, char** argv) {
    int arr[] = {4, 7, 2, 6, 9, 1, 8, 3};
    printArr(arr);
    insertionSort(arr);
    printArr(arr);
    return 0;
}