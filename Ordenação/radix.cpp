#include <bits/stdc++.h>
using namespace std;

template <size_t S>
void printArr(int (&arr)[S]) {
    cout << "[" << arr[0];
    for (int i = 1; i < S; i++)
        cout << ", " << arr[i];
    cout << "]" << endl;
}

int expbin(int number, int exp) {
    if (!exp)
        return 1;
    if (exp & 1)
        return expbin(number, exp - 1) * number;
    int result = expbin(number, exp >> 1);
    return result * result;
}

int getDigit(int number, int pos) {
    return number/expbin(10, pos - 1) % 10;
}

template <size_t S>
void radixSortA(int (&arr)[S]) {
    int 
        digits[10][S],
        lengths[10], 
        digit, i , j, currentPos = 0;
    bool end = false;
    memset(lengths, 0, sizeof(lengths));

    while (currentPos++, !end) {
        for (i = 0; i < S; i++) {
            digit = getDigit(arr[i], currentPos);
            digits[digit][lengths[digit]++] = arr[i];
        }

        end = lengths[0] != S;

        i = j = 0;
        while (i < S) {
            while (lengths[j]--) 
                arr[i++] = digits[j][lengths[j]];
            j++;
        }
    }
}

int main(int argc, char** argv) {
    int array[] = {3, 2, 1, 4, 6, 8, 5};

    printArr(array);
    radixSortA(array);
    printArr(array);

    return 0;
}