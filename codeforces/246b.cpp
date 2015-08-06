#include <cstdio>

int main() {
    int n, s = 0, tmp;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &tmp);
        s += tmp;
    }
    if (s % n == 0) printf("%d\n", n);
    else printf("%d\n", n-1);
}
