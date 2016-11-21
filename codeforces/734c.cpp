#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#  define debug(args...) {}
#else
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 500004;
const int modn = 1000000007;

ll n, m, k, x, mana, ans;
ll a[MAXN], b[MAXN], c[MAXN], d[MAXN];

int main() {
    scanf(" %lld %lld %lld", &n, &m, &k);
    scanf(" %lld %lld", &x, &mana);
    for (int i = 0; i < m; i++)
        scanf(" %lld", a + i);
    for (int i = 0; i < m; i++)
        scanf(" %lld", b + i);
    for (int i = 0; i < k; i++)
        scanf(" %lld", c + i);
    for (int i = 0; i < k; i++)
        scanf(" %lld", d + i);

    ans = n * x;

    for (int i = 0; i < m; i++)
        if (b[i] <= mana) ans = min(ans, n * a[i]);
    for (int i = 0; i < k; i++)
        if (d[i] <= mana) ans = min(ans, (n - c[i]) * x);

    for (int i = 0; i < m; i++) {
        if (b[i] > mana) continue;
        ll c_mana = mana - b[i];
        ll c_i = upper_bound(d, d + k, c_mana) - d - 1;
        if (c_i < 0) continue;
        ans = min(ans, (n - c[c_i]) * a[i]);
    }
    printf("%lld\n", ans);
}

