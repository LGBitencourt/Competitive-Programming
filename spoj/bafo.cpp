#include <cstdio>

int main() {
    int t, A, B, n, a, b;
    t = 0;
    while (scanf(" %d", &n), n != 0) {
        A = B = 0;
        for (int i = 0; i < n; i++) {
            scanf(" %d %d", &a, &b);
            A += a, B += b;
        }
        printf("Teste %d\n", ++t);
        if (A > B) printf("Aldo\n\n");
        else printf("Beto\n\n");
    }
}
