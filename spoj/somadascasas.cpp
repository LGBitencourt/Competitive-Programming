#include <cstdio>

#define MAX 1000000

int main() {
    int n, k;
    int c[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }
    scanf("%d", &k);
    int end = n - 1;
    for (int j = 0; j < n; j++) {
        if ((c[j] + c[end]) == k) {
            printf("%d %d\n", c[j], c[end]);
            break;
        } else if (c[j] + c[end] > k) {
            j--, end--;
        }
    }
}