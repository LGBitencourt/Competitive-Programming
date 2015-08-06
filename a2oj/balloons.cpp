#include <cstdio>

int main() {
    int t, x, y, n, k;
    int v[2];
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d %d %d", &n, &x, &y);
        for (int i = 1; i <= n; i++) {
            scanf(" %d", &k);
            if (i == 1) v[0] = k;
            else if (i == n) v[1] = k;
        }
        if (v[0] == x && v[1] == y) printf("BOTH\n");
        else if (v[0] == x) printf("EASY\n");
        else if (v[1] == y) printf("HARD\n");
        else printf("OKAY\n");
    }
}
