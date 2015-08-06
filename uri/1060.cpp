#include <cstdio>

int main() {
    int cont = 0;
    float n;
    while(scanf("%f", &n) != EOF) {
        if (n > 0) cont++;
    }
    printf("%d valores positivos\n", cont);
    return 0;
}
