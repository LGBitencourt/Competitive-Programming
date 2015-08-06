#include <cstdio>

int main() {
    int a[5];
    int sum = 0, i = 0;
    char c[100500];
    scanf("%d %d %d %d", &a[1], &a[2], &a[3], &a[4]);
    scanf(" %s", c);
    while (c[i] != '\0') {
        sum += a[c[i++] - '0'];
    }
    printf("%d\n", sum);
}
