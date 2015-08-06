#include <cstdio>

int main() {
    int n, h;
    double v;
    scanf("%d %d", &n, &h);
    scanf("%lf", &v);
    printf("NUMBER = %d\nSALARY = U$ %.2lf\n", n, h*v);
    return 0;
}
