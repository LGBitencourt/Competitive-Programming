#include <iostream>
#include <algorithm>

#define MAX_I 1000005

using namespace std;

long long int primes[MAX_I];
bool c[MAX_I];
int p = 0;


void crivo() {
    for (int i = 0; i < MAX_I; i++) c[i] = true;
    for (int i = 2; i < MAX_I; i++) {
        if (!c[i]) continue;
        for (int j = 2*i; j < MAX_I; j += i)
            c[j] = false;
    }
    for (int i = 2; i < MAX_I; i++)
        if (c[i]) primes[p++] = (long long int) i * i;
}

int main() {
    crivo();
    int n;
    long long int x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (binary_search(primes, primes + p, x))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
