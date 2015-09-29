#include <cstdio>

#define MAX 1000005

bool p[MAX];
bool v[MAX];
int primes[MAX];
int j = 0;

void crivo() {
    for (int i = 2; i < MAX; i++) p[i] = true;
    for (int i = 2; i * i < MAX; i++) {
        if (!p[i]) continue;
        for (int j = i * i; j < MAX; j += i)
            p[j] = false;
    }
    for (int i = 2; i < MAX; i++)
        if (p[i]) primes[j++] = i;
}

int main() {
    int t;
    crivo();
    scanf(" %d", &t);
    while (t--) {
        int x, y;
        scanf(" %d %d", &x, &y);
        for (int i = 0; i <= y - x; i++) v[i] = true;
        for (int i = 0; i < j && primes[i] * primes[i] <= y; i++) {
            int k = (((x + primes[i] - 1)/primes[i])*primes[i]);
            if (k == primes[i]) k += primes[i];
            k -= x;
            for (int w = k; w <= y - x; w += primes[i])
                v[w] = false;
        }
        for (int i = 0; i <= y - x; i++)
            if (v[i] && x + i != 1) printf("%d\n", x + i);
    }
}

