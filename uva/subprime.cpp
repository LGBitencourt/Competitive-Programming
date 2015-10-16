#include <cstdio>

int main() {
    int cash[20];
    int b, n, willpay;

    do {
        willpay = 1;
        scanf("%d %d", &b, &n);
        if(b != 0 && n != 0) {
            for(int k = 0; k < b; k++) {
                scanf("%d", &cash[k]);
            }

            for(int i = 0; i < n; i++) {
                int a, b, c; scanf("%d %d %d", &a, &b, &c);
                a--, b--;
                cash[a] -= c;
                cash[b] += c;
            }

            for(int i = 0; i < b; i++) {
                if(cash[i] < 0) {
                    willpay = 0;
                    break;
                }
            }

            if(!willpay) {
                printf("N\n");
            } else {
                printf("S\n");
            }

        }

    } while (b != 0 && n != 0);

    return 0;
}
