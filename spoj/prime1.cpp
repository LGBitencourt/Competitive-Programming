#include <cstdio>

#define MAX 1000000005

bool p[MAX];

void crivo() {
    for (int i = 2; i < MAX; i++) p[i] = true;
    for (int i = 2; i * i < MAX; i++) {
        if (!p[i]) continue;
        for (int j = i * i; j < MAX; j += i)
            p[j] = false;
    }
}

int main() {
    int t, f = 1;
    crivo();
    printf("hue\n");
    scanf(" %d", &t);
    while (t--) {
        int i, j;
        if (!f)
            putchar('\n');
        f = 0;
        scanf(" %d %d", &i, &j);
        while (i <= j) {
            if (p[i]) printf("%d\n", i);
            i++;
        }
    }
}
