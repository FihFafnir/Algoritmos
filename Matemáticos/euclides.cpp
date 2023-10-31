#include <bits/stdc++.h>
using namespace std;

int gdc(int a, int b) {
    return !b ? a : gdc(b, a % b); 
}

int main(int argc, char** argv) {
    int a, b;
    scanf(" %d %d", &a, &b);
    printf("Máximo divisor comum: %d\n", gdc(a, b));
    return 0;
}