#include <cstdio>

int main() {
    int reais, centavos, n100, n50, n20, n10, n5, n2, m100, m50, m25, m10, m5, m1;
    double v, tmp;
    scanf("%lf", &v);
    centavos = (int) (v*100) % 100;
    reais = (v * 100) / 100;
    n100 = reais / 100, reais = reais % 100;
    n50 = reais / 50, reais = reais % 50;
    n20 = reais / 20, reais = reais % 20;
    n10 = reais / 10, reais = reais % 10;
    n5 = reais / 5, reais = reais % 5;
    n2 = reais / 2, reais = reais % 2;
    if (reais > 0) centavos += 100;
    m100 = centavos / 100, centavos = centavos % 100;
    m50 = centavos / 50, centavos = centavos % 50;
    m25 = centavos / 25, centavos = centavos % 25;
    m10 = centavos / 10, centavos = centavos % 10;
    m5 = centavos / 5, centavos = centavos % 5;
    m1 = centavos;

    printf("NOTAS:\n");
    printf("%d nota(s) de R$ 100.00\n", n100);
    printf("%d nota(s) de R$ 50.00\n", n50);
    printf("%d nota(s) de R$ 20.00\n", n20);
    printf("%d nota(s) de R$ 10.00\n", n10);
    printf("%d nota(s) de R$ 5.00\n", n5);
    printf("%d nota(s) de R$ 2.00\n", n2);

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", m100);
    printf("%d moeda(s) de R$ 0.50\n", m50);
    printf("%d moeda(s) de R$ 0.25\n", m25);
    printf("%d moeda(s) de R$ 0.10\n", m10);
    printf("%d moeda(s) de R$ 0.05\n", m5);
    printf("%d moeda(s) de R$ 0.01\n", m1);

    return 0;
}
