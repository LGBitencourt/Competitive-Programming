#include <cstdio>

int notas[105];

int main() {
    int n, m;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &m);
        notas[m]++;
    }
    m = 0;
    int index;
    for (int i = 104; i >= 0; i--) {
        if (notas[i] > m) index = i, m = notas[i];
    }
    printf("%d\n", index);
}
