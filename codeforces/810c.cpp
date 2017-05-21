#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int modn = 1000000007;
const int inf = 0x3f3f3f3f;
const int MAXN = 312345;

ll n;
ll a[MAXN];

ll fexp (ll a, ll b) {
    if (b == 0ll) return 1ll;
    else if (b == 1ll) return a % modn;
    else if (b % 2ll == 0ll) return fexp ((a * a) % modn, b / 2ll);
    return (a * fexp ((a * a) % modn, b / 2ll)) % modn;
}

ll f(int i) {
    if (i == 1) return -(fexp(2ll, n - 1) - 1);
    if (i == n) return (fexp(2ll, n - 1) - 1);
    return fexp(2ll, i - 1) - fexp(2ll, n - i);
}

int main() {
    scanf(" %lld", &n);
    for (int i = 1; i <= n; i++)
        scanf(" %lld", a + i);
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + (a[i] * f(i) % modn)) % modn;
    printf("%lld\n", ans % modn);
}

