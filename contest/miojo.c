#include <stdio.h>

int maior(int a, int b) {
    if (a > b) return a;
    return b;
}

int abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    long long int t, a, b, n, m;
    while (scanf("%lld %lld %ld", &t, &a, &b) != EOF) {
        n = 1;
        m = 0;
       
        if (t == 0) printf("0\n");
        else { 
        while (t % abs((n * a) - (m * b)) != 0) {
            m++;
            if (t % abs((n * a) - (m * b)) == 0) break;
            n++;
        }

        printf("%d\n", maior(n*a, m*b));
        }
    }

    return 0;
}
