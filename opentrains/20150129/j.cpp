#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    int n;
    ll num;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %lld", &num);
        for (ll j = 0; j < 256; j++) {
            if (((j ^ (j << 1)) % 256) == num) {
                    printf ("%lld ", j);
                break;
            }
        }
    }
    printf ("\n");
}
