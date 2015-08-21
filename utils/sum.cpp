#include <cstdio>

int v[5] = {1, 2, 3, 4, 5};

int sum(int n) {
    if (n == 1)
        return v[0];
    return v[n-1] + sum(n-1);
}

int main() {
    printf("%d\n", sum(5));
}
