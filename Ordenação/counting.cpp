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
void countingSort(int (&arr)[S]) {
    int maxValue = arr[0],
        minValue = arr[0];
    for (int i = 1; i < S; i++) {
        if (maxValue < arr[i])
            maxValue = arr[i];
        if (minValue > arr[i])
            minValue = arr[i];
    }

    int aux[S], pos[maxValue - minValue + 1], i;

    for (i = 0; i < S; i++)
        aux[i] = arr[i];

    memset(pos, 0, sizeof(pos));

    for (i = 0; i < S; i++)
        pos[aux[i] - minValue]++;

    for (i = 1; i <= maxValue - minValue; i++)
        pos[i] += pos[i-1];
    
    for (i = 0; i < S; i++)
        arr[--pos[aux[i] - minValue]] = aux[i];
}


int main(int argc, char** argv) {
    int arr[] = {4, 7, 8, -9, 9, 10, 2, -3};
    countingSort(arr);
    printArr(arr);    
    return 0;
}