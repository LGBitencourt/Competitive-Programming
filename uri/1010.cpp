#include <cstdio>

int main() {
    int p, n;
    double v, t = 0.00;
    for (int i = 0; i < 2; i++) {
        scanf("%d %d %lf", &p, &n, &v);
        t += n*v;
    }
    printf("VALOR A PAGAR: R$ %.2lf\n", t);
    return 0;
}
