#include <cstdio>


int max (int a, int b) {
    if (a > b) return a;
    else return b;
}

int vmax(int v[], int n, int i) {
    if (i == n - 1) return v[i];
    return max(v[i], vmax(v, n, i + 1));
}

int main() {
    int v[10] = {1, 3, 521, 2, 36, -6, 48, 72, 0, 42};
    printf("%d\n", vmax(v, 10, 0));
}
