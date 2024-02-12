#include <bits/stdc++.h>

using namespace std;

template <size_t S>
void printArr(int (&arr)[S]) {
    cout << "[" << arr[0];
    for (int i = 1; i < S; i++)
        cout << ", " << arr[i];
    cout << "]" << endl;
}

void swap(int& first, int& second) {
    int tmp = first;
    first = second;
    second = tmp;
}

template <size_t S>
void selectionSort(int (&arr)[S]) {
    size_t i, j;
    for (i = 0; i < S; i++)
        for (j = i + 1; j < S; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

int main(int argc, char** argv) {
    int array[] = {4, 7, 9, 6, 5, 2, 1, 8, 3};
    printArr(array);
    selectionSort(array);
    printArr(array);
    return 0;
}