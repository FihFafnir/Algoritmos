#include <bits/stdc++.h>
using namespace std;

int expbin(int number, int exp) {
    if (!exp)
        return 1;
    if (exp & 1)
        return expbin(number, exp - 1) * number;
    int result = expbin(number, exp/2);
    return result * result;
}

int getDigit(int number, int pos) {
    return number/expbin(10, pos - 1) % 10;
} 

void radixSortA(int arr[], int length) {
    int 
        digits[10][length], 
        lengths[10], 
        digit, i , j, d = 0;
    bool end = false;
    memset(lengths, 0, sizeof(lengths));

    while (d++, !end) {
        for (i = 0; i < length; i++) {
            digit = getDigit(arr[i], d);
            digits[digit][lengths[digit]++] = arr[i];
        }

        end = lengths[0] != length;

        i = j = 0;
        while (i < length) {
            while (lengths[j]--) 
                arr[i++] = digits[j][lengths[j]];
            j++;
        }
    }
}

void radixSortB(int arr[], int length) {
    int 
        newArr[length],
        pos[10],
        lengths[10], 
        digit, i, j, d = 0;
    bool end = false;

    while (d++, !end) {
        memset(pos, 0, sizeof(pos));
        memset(lengths, 0, sizeof(lengths));
        
        for (i = 0; i < length; i++) {
            digit = getDigit(arr[i], d);
            for (j = digit; j < 10; j++)
                pos[j]++;
        }


        for (i = 0; i < length; i++) {
            digit = getDigit(arr[i], d);
            newArr[(digit ? pos[digit-1] : 0) + lengths[digit]++] = arr[i];
        }

        end = true;
        for (i = 0; i < length; i++)
            if (arr[i] != newArr[i]) {
                arr[i] = newArr[i];
                end = false;
            }
    }
}

int main(int argc, char** argv) {
    int arr[] = {2, 3, 5, 4, 6, 1, 0, 7, 8, 9};
    for (int i = 0; i < 10; i++)
        printf("%d, ", arr[i]);
    printf("\n");
    radixSortB(arr, 10);
    for (int i = 0; i < 10; i++)
        printf("%d, ", arr[i]);
    printf("\n");
    return 0;
}