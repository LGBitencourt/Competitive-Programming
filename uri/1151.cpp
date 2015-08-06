#include <cstdio>

int main() {
    int n, a, c = 0, p = 0;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        if (p == 0) {
            printf("%d ", p);
            a = p;
            p = 1;
            continue;
        } else if (p == 1 && c == 0) {
            printf("%d ", p);
            c = p;
            p = p + 1;
            continue;
        }

        p = a + c;
        printf("%d", p);
        a = c;
        c = p;

        if (i != n-1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    return 0;
}
