#include <cstdio>

int main() {
    int a, b, sum = 0, temp;
    scanf("%d %d", &a, &b);
    if (a < b) {
        temp = b;
        b = a;
        a = temp;
    }

    while (a >= b) {
        if (b % 13 != 0) sum += b; 
        b++;
    }

    printf("%d\n", sum);

    return 0;
}
