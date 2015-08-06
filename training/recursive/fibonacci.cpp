#include <cstdio>

int states[100] = {0};

int fibonacci(int n, int calls) {

    if (n == 0 || n == 1) return n;

    if (states[n] == 0) states[n] = fibonacci(n-1) + fibonacci(n - 2);

    return states[n];
}

int main() {
    int n, t;
    scanf(" %d", &n);
    printf("fib(%d) = %d\n", n, fibonacci(n));
}
