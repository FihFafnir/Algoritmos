#include <bits/stdc++.h>
using namespace std;

int c = 0;

int binarySearch(int arr[], int length, int element) {
    int start = 0, end = length - 1, middle;
    while (start <= end) {
        middle = (end + start)/2;
        if (element == arr[middle])
            return middle;
        if (element > arr[middle]) 
            start = middle + 1;
        else end = middle - 1;
        c++;
    }
    return -1;
}

int main(int argc, char** argv) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    printf("%d\n", binarySearch(arr, 20, 8));
    printf("%d\n", c);
    return 0;
}