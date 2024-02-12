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
void cocktailShakerSort(int (&arr)[S]) {
    size_t i, left, right;

    left = 1;
    right = S;

    while (left < right) {
        for (i = left; i < right; i++)
            if (arr[i - 1] > arr[i])
                swap(arr[i - 1], arr[i]);
        right--;
        for (i = right - 1; i >= left; i--)
            if (arr[i - 1] > arr[i])
                swap(arr[i - 1], arr[i]);
        left++;
    }
}

int main(int argc, char** argv) {
    int arr[] = {4, 7, 2, 6, 9, 1, 8, 3};
    printArr(arr);
    cocktailShakerSort(arr);
    printArr(arr);
    return 0;
}