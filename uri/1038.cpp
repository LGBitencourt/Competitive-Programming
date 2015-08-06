#include <cstdio>

int main() {
    double v[5] = {4, 4.5, 5, 2, 1.5};
    int x, y;
    scanf("%d %d", &x, &y);

    printf("Total: R$ %.2lf\n", y*v[x-1]);

}
