#include <cstdio>

int main() {
    int v, n50, n10, n5, n1, t = 1;
    while (scanf(" %d", &v), v != 0) {
        n50 = n10 = n5 = n1 = 0;
        n50 = v/50, v = v % 50;
        n10 = v/10, v = v % 10;
        n5 = v/5, v = v % 5;
        n1 = v;
        printf("Teste %d\n%d %d %d %d\n\n", t++, n50, n10, n5, n1);
    }
}
