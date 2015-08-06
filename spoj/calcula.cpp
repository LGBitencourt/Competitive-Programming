#include <cstdio>

int main() {
    int n, x, t = 1, sum;

    while (scanf(" %d", &n), n != 0) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %d", &x);
            sum += x;
        }
        printf("Teste %d\n%d\n\n", t++, sum);
    }

    return 0;
}
