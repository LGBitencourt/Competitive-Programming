#include <cstdio>

int main() {
    int n, y, m, d;
    y = m = d = 0;
    scanf("%d", &n);
    while(n > 0) {
        if(n - 365 >= 0) {
            y++;
            n -= 365;
        } else if (n - 30 >= 0) {
            m++;
            n -= 30;
        } else {
            d++, n--;
        }
    }
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", y, m, d);
    return 0;
}
