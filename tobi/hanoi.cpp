#include <cstdio>

int fastexp(int n, int p) {
    if (p == 0) return 1;
    if (!(p % 2)) return fastexp (n * n, p/2);
    return n * fastexp (n * n, p/2);
}

int main() {
    int n, t = 1;
    while (scanf(" %d", &n), n != 0) {
        printf("Teste %d\n%d\n\n", t++, fastexp(2, n) - 1);
    }
}
