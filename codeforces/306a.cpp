#include <cstdio>

int main() {
    int n, m, q, r, sum = 0, first = 1;
    scanf("%d %d", &n, &m);

    r = n % m;
    q = n/m;

    for (int i = 0; i < m; i++) {
        int v = q;
        if (r > 0) r--, v++;
        if (!first) printf(" ");
        printf("%d", v);
        first = 0;
    }

    printf("\n");

}
