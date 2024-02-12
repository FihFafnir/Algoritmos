#include <bits/stdc++.h>
using namespace std;

int expbin(int number, int exp) {
    if (!exp)
        return 1;
    if (exp & 1)
        return expbin(number, exp - 1) * number;
    int result = expbin(number, exp >> 1);
    return result * result; 
}

int getDigit(int number, int pos) {
    return (number % expbin(10, pos)) / 10;
}

int main(int argc, char** argv) {
    printf("%d\n", expbin(9,2));
    printf("%d\n", getDigit(253, 2));
    return 0;
}