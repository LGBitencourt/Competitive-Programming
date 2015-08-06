#include <cstdio>
#include <stdlib.h>

int main() {
    int a, b, c, m, n;
    scanf("%d %d %d", &a, &b, &c);
    m = (a+b+abs(a-b))/2;
    n = (m+c+abs(m-c))/2;
    printf("%d eh o maior\n", n);
    return 0;
}
