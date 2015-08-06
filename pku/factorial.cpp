#include <cstdio>

int main() {
    int t, n;

    scanf("%d", &t);

    while (t--) {
        int s = 0;
        scanf(" %d", &n);
        for (int i = 5; n/i >= 1; i *= 5) {
            s += n/i;
        }
        printf("%d\n", s);
    }
}
