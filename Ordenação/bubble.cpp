#include <bits/stdc++.h>

using namespace std;

void swap(int& first, int& second) {
    int tmp = first;
    first = second;
    second = tmp;
}

template <size_t S>
void printArr(int (&arr)[S]) {
    cout << "[" << arr[0];
    for (int i = 1; i < S; i++)
        cout << ", " << arr[i];
    cout << "]" << endl;
}

template <size_t S>
void bubbleSort(int (&arr)[S]) {
    int i, j;
    for (i = S; i > 1; i--)
        for (j = 1; j < i; j++)
            if (arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
}

int main(int argc, char** argv) {
    int arr[] = {4, 7, 2, 6, 9, 1, 8, 3};
    printArr(arr);
    bubbleSort(arr);
    printArr(arr);
    return 0;
}