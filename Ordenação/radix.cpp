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
    return (number/expbin(10, pos)) % 10;
}

int getNumberOfDigits(int number) {
    int numberOfDigits;
    for (numberOfDigits = 0; number % 10; numberOfDigits++)
        number /= 10;
    return numberOfDigits;
}

template <size_t S>
void radixSort(int (&arr)[S]) {
    int digits[10][S], lengths[10];
    int currentDigit, digit, i , j;

    memset(lengths, 0, sizeof(lengths));

    int maxValue = arr[0];
    for (i = 1; i < S; i++)
        if (maxValue < arr[i])
            maxValue = arr[i];

    int maxNumberOfDigits = getNumberOfDigits(maxValue);
    for (currentDigit = 0; maxNumberOfDigits--; currentDigit++) {
        for (i = 0; i < S; i++) {
            digit = getDigit(arr[i], currentDigit);
            digits[digit][lengths[digit]++] = arr[i];
        }

        for (i = j = 0; i < S; j++)
            while (lengths[j]--) 
                arr[i++] = digits[j][lengths[j]];
    }
}

int main(int argc, char** argv) {
    int array[] = {3, 2, 1, 4, 6, 8, 5};

    printArr(array);
    radixSort(array);
    printArr(array);

    return 0;
}