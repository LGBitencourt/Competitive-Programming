#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int main() {
    ll n, k, ma = -inf;
    scanf(" %lld %lld", &n, &k);
    for (ll i = 0; i < n; i++) {
        ll f, t;
        scanf(" %lld %lld", &f, &t);
        if (t > k) ma = max(ma, f - (t - k));
        else ma = max(ma, f);
    }
    printf("%lld\n", ma);
}

