#include <bits/stdc++.h>
using namespace std;

void swap(int& first, int& second) {
    if (first == second)
        return;

    first ^= second;
    second ^= first;
    first ^= second;
}

int main(int argc, char** argv) {
    int x, y;
    scanf("%d %d", &x, &y);
    swap(x, y);
    printf("A: %d\nB: %d\n", x, y);
}