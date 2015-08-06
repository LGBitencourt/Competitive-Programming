#include <cstdio>

int main() {
    int x1, x2, y1, y2, x, y, t, c, a = 1;

    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2), x1 != 0 || y1 != 0 || x2 != 0 || y2 != 0) {
        scanf("%d", &t);
        c = 0;
        for (int i = 1; i <= t; i++) {
            scanf("%d %d", &x, &y);
            if (x <= x2 && x >= x1 && y <= y1 && y >= y2) c++;
        }
        printf("Teste %d\n", a++);
        printf("%d\n\n", c);
    }
}
