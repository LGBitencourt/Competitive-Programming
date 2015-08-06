#include <cstdio>

int c = 0;

int fib(int n) {
    n++;
    c += 1;
    if (n == 1 || n == 2) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int i, n;
    scanf("%d", &i);
    while (i > 0) {
        scanf("%d", &n);
        printf("fib(%d) = %d calls = %d\n", n, fib(n), c);
        i--;
    }
}