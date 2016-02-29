#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

bool prime[MAX];
int big_prime[MAX], l[30];

void crivo() {
    for (int i = 2; i < MAX; i++)
        prime[i] = true, big_prime[i] = i;
    for (int i = 2; i < MAX; i++) {
        if (!prime[i]) continue;
        for (int j = 2*i; j < MAX; j += i) {
            prime[j] = false;
            big_prime[j] = i;
        }
    }
}

int main () {
    int n, k;
    crivo();
    while (scanf (" %d %d", &n, &k) && n != 0) {

    }
}
