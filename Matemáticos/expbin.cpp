#include <bits/stdc++.h>
using namespace std;

int expbin(int base, int exp) {
    if (!exp) return 1;
    if (exp & 1) return base * expbin(base, exp - 1);
    int result = expbin(base, exp >> 1);
    return result * result;
}

int main(int argc, char** argv) {
    int a, b;
    scanf(" %d %d", &a, &b);
    printf("%d\n", expbin(a, b));
    return 0;
}