#include <cstdio>

int main() {
    int n, x, sum;

    scanf("%d", &n);

    while(n > 0) {
        sum = 0;
        scanf("%d", &x);
        int i = x - 1;
        for(i; i > 0; i--) {
            if(x % i == 0) {
                sum += i;
            }
        }
        if(sum == x) {
            printf("%d eh perfeito\n", x);
        } else {
            printf("%d nao eh perfeito\n", x);
        }
        n--;
    }

    return 0;
}
