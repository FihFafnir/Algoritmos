#include <bits/stdc++.h>
using namespace std;

template <size_t S> void printArr(int (&arr)[S]) {
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

int getDigit(int number, int pos) { return (number / expbin(10, pos)) % 10; }

int getNumberOfDigits(int number) {
    int numberOfDigits;
    for (numberOfDigits = 0; number % 10; numberOfDigits++)
        number /= 10;
    return numberOfDigits;
}

template <size_t S> int getMaxValue(int (&arr)[S]) {
    int maxValue = arr[0];
    for (int i = 1; i < S; i++)
        if (maxValue < arr[i])
            maxValue = arr[i];
    return maxValue;
}

template <size_t S> void radixSort(int (&arr)[S]) {
    int digits[10][S], lengths[10];
    int currentDigit, digit, i, j;

    int maxNumberOfDigits = getNumberOfDigits(getMaxValue(arr));
    for (currentDigit = 0; currentDigit < maxNumberOfDigits; currentDigit++) {
        memset(lengths, 0, sizeof(lengths));

        for (i = 0; i < S; i++) {
            digit = getDigit(arr[i], currentDigit);
            digits[digit][lengths[digit]++] = arr[i];
        }

        for (i = digit = 0; digit < 10; digit++)
            for (j = 0; j < lengths[digit]; j++)
                arr[i++] = digits[digit][j];
    }
}

int main(int argc, char **argv) {
    int array[] = {31199, 11851, 23234, 14616, 28686, 7608, 973,   4167,
                   19163, 26242, 12435, 2685,  17835, 580,  32541, 6169,
                   26689, 2403,  2138,  24275, 12802, 659,  2224,  19543,
                   1817,  28323, 13765, 22411, 31590, 26687};
    printArr(array);
    radixSort(array);
    printArr(array);

    return 0;
}
