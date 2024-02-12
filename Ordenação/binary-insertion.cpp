#include <bits/stdc++.h>

using namespace std;

template <size_t S>
void printArr(int (&arr)[S]) {
    cout << "[" << arr[0];
    for (int i = 1; i < S; i++)
        cout << ", " << arr[i];
    cout << "]" << endl;
}

template <size_t S>
size_t binarySearch(int (&arr)[S], size_t index) {
    int tmp = arr[index];
    
    size_t 
        start = 0,
        end = index,
        middle;
    
    while (middle = (end + start) >> 1, middle && start < end) 
        if (arr[middle] > tmp)
            end = middle - 1;
        else
            start = middle + 1;

    return middle;

}

template <size_t S>
void insertionSort(int (&arr)[S]) {
    size_t i, j, index;
    int tmp;

    for (i = 0; i < S; i++) {
        printArr(arr);
        tmp = arr[i];
        index = binarySearch(arr, i);
        for (j = i; j > index; j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp;
    }
}

int main(int argc, char** argv) {
    int array[] = {4, 7, 8, 9, 1, 2, 6, 3, 5};
    printArr(array);
    insertionSort(array);
    printArr(array);
    return 0;
}