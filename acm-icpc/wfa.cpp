#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    double lprice, uprice, price, dif = 0.00, eps = 0.00001;
    int p, a, b, c, d, n;

    scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n);
    lprice = uprice = p*(sin(a + b) + cos(c + d) + 2);
    for (int i = 1; i <= n; i++) {
        price = p*(sin((a*i) + b) + cos((c*i) + d) + 2);
        if (price > uprice + eps) uprice = lprice = price;
        else if (price < lprice - eps) lprice = price;
        if (uprice - lprice > dif + eps) dif = uprice - lprice;
    }
    printf("%.8f\n", dif);
}
