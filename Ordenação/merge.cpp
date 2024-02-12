#include <bits/stdc++.h>

using namespace std;

template <size_t S>
void merge(int (&arr)[S], int (&aux)[S], size_t start, size_t middle, size_t end) {
    size_t 
        left = start, 
        right = middle, i;

    for (i = start; i < end; i++)
        aux[i] = arr[i];
    
    for (i = start; i < end; i++) 
        arr[i] = 
            (right >= end || (left < middle && aux[left] < aux[right])) 
                ? aux[left++] : aux[right++];
}

template <size_t S>
void mergeSort(int (&arr)[S], int (&aux)[S], size_t start, size_t end) {
    size_t middle = (end + start) >> 1;
    if (start < end - 1) {
        mergeSort(arr, aux, start, middle);
        mergeSort(arr, aux, middle, end);
    }

    merge(arr, aux, start, middle, end);
}

template <size_t S>
void mergeSort(int (&arr)[S]) {
    int aux[S];
    mergeSort(arr, aux, 0, S);
}

int main(int argc, char** argv) {
    int array[] = {4, 7, 2, 6, 9, 1, 8, 3};
    mergeSort(array);
    for (int i = 0; i < 8; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}