#include <stdio.h>

int main() {
    int a, b;

    while(scanf("%d %d", &a, &b) != EOF) {
        if (a % b == 0 || b % a == 0) printf("Y\n");
        else printf("N\n");
    }

    return 0;
}
