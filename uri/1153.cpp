#include <cstdio>

int main() {
    int n, m, i;
    scanf("%d", &n);

    m = n;
    for(i = 1; i < n; i++) {
        m = m * (n - i);
    }

    printf("%d\n", m);

    return 0;
}
