#include <cstdio>
#include <stdlib.h>

int main() {
    int n, m, x, sum = 0;
    scanf(" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &x);
        sum += abs(m - x);
    }
    printf("%d\n", sum/2);
}
