#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 212345;

ll n, b[MAXN], acc[MAXN];

int main() {
    scanf(" %lld", &n);
    for (int i = 0; i < n; i++)
        scanf(" %lld", &b[i]);
    acc[0] = b[0];
    for (int i = 1; i < n; i++)
        acc[i] = acc[i - 1] + b[i];
    ll ans = 0;
    for (int i = 1; i < n; i++)
        ans = max(ans, acc[i - 1] * (acc[n - 1] - acc[i - 1]));
    printf("%lld\n", ans);
}

