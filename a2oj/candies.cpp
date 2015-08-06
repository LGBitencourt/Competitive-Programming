#include <cstdio>

int main() {
    int t, n, k, f, c;
    scanf(" %d", &t);
    while (t--) {
        f = 0;
        scanf(" %d %d", &n, &k);
        while (n--) {
            scanf(" %d", &c);
            f += c/k;
        }
        printf("%d\n", f);
    }
}
