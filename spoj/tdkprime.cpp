#include <cstdio>

#define MAX 86100007

typedef unsigned int ui;

ui p[2690639], x = 0;
int primes[MAX];
int j = 0;

void crivo() {
    for (ui i = 2; i*i < MAX; i++) {
        if (!(p[i>>5]&(1 << (i & (1 << 6)-1)))) {
            for (ui j = i*i; j < MAX; j += i)
                p[j>>5] |= (1<<(j&(1<<6)-1));
        }
    }
    for (ui i = 2; i < MAX; i++) {
        if (!(p[i>>5] & (1<<(i&(1<<6)-1)))) primes[j++] = i;
        if (j > 5000001) break;
    }
}

int main () {
    crivo ();
    int n, x;
    scanf (" %d", &n);
    while (n--) {
        scanf (" %d", &x);
        printf ("%d\n", primes[--x]);
    }
}
