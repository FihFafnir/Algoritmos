#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main(int argc, char** argv) {
    int x, y;
    scanf("%d %d", &x, &y);
    swap(&x, &y);
    printf("A: %d\nB: %d\n", x, y);
}