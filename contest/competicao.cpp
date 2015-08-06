#include <cstdio>

int main() {
    int n, k;
    while(scanf("%d %d", &n, &k) != EOF) {
        if (n % (k+1) == 0) printf("Carolina\n");
        else printf("Colombo\n");
    }
    return 0;
}
