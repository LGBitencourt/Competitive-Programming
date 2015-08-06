#include <cstdio>

int main() {
    int n, maior, c = 1, d;
         
    scanf("%d", &maior);

    while(scanf(" %d", &n) != EOF) {
        c++;
        if (n > maior) {
            maior = n;
            d = c;
        }
    }
                 
    printf("%d\n", maior);
    printf("%d\n", d);
                         
    return 0;
}
