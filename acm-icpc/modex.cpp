#include <cstdio>

long long int modx(long long int x, long long int y, long long int n) {
    if (y == 0) return 1;
    if (y == 1) return x % n;
    if(y % 2 == 0) return modx((x*x) % n, y/2, n) % n;
    else return x*modx((x*x) % n, y-1, n) % n;
}

int main() {
    long long int c, x, y, n;

    while (scanf(" %lld", &c), c != 0) {
        for (int i = 0; i < c; i++) {
            scanf(" %lld %lld %lld", &x, &y, &n);
            printf("%lld\n", modx(x, y, n));
        }
    }
}
