#include <cstdio>

int main() {
    int n, m , p;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &m ,&p);
        printf("%d\n", m+p);
    }
}
