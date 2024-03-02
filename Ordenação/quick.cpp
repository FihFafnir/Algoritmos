#include <bits/stdc++.h>

using namespace std;

void swap(int &first, int &second) {
    int tmp = first;
    first = second;
    second = tmp;
};

template <size_t S>
size_t getPivotIndex(int (&arr)[S], size_t start, size_t end) {
    size_t middle = (end + start) >> 1;

    if (arr[start] < arr[middle]) {
        if (arr[middle] < arr[end])
            return middle;
        return arr[start] < arr[end] ? end : start;
    }

    if (arr[start] < arr[end])
        return start;
    return arr[middle] < arr[end] ? end : middle;
}

template <size_t S>
void quickSort(int (&arr)[S], size_t start = 0, size_t end = S - 1) {
    size_t pivot = getPivotIndex(arr, start, end);
    size_t left = start, right = end;

    while (left <= right) {
        while (arr[pivot] < arr[right])
            right--;
        while (arr[pivot] > arr[left])
            left++;

        if (left <= right)
            swap(arr[left++], arr[right--]);
    }

    if (start < right)
        quickSort(arr, start, right);
    if (left < end)
        quickSort(arr, left, end);
}

int main(int argc, char **argv) {
    int arr[] = {4, 7, 2, 6, 9, 1, 8, 3};
    quickSort(arr);
    for (int &i : arr)
        cout << i << endl;
    return 0;
}
