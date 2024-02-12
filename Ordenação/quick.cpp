#include <bits/stdc++.h>

using namespace std;

void swap(int& first, int& second) {
    int tmp = first;
    first = second;
    second = tmp;
};

template <size_t S>
int getPivot(int (&arr)[S], size_t start, size_t end) {
    size_t middle = (end + start) >> 1;
    int maxValue = max(max(arr[end - 1], arr[middle]), arr[start]);
    int minValue = min(min(arr[end - 1], arr[middle]), arr[start]);

    return arr[start] + arr[middle] + arr[end - 1] - maxValue - minValue;
}

template <size_t S>
void quickSort(int (&arr)[S], size_t start = 0, size_t end = S) {
    int pivot = getPivot(arr, start, end);
    size_t left = start, right = end - 1;

    while (left < right) {
        while (pivot < arr[right])
            right--;
        while (pivot > arr[left])
            left++;

        if (left < right)
            swap(arr[left], arr[right]);
    }

    if (start < left)
        quickSort(arr, start, left);
    if (left + 1 < end)
        quickSort(arr, left + 1, end);
}


int main(int argc, char** argv) {
    int arr[] = {4, 7, 2, 6, 9, 1, 8, 3};
    quickSort(arr);
    return 0;
}