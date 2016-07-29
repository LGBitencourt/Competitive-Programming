#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define LLD "%I64d"
#  define debug(args...) {}
#else
#  define LLD "%lld"
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 100004;
const int modn = 1000000007;

int n, m;
ll a[MAXN], b[MAXN];

int main() {
    scanf (" %d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf (" %lld", &a[i]);
    for (int i = 0; i < m; i++)
        scanf (" %lld", &b[i]);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll d = inf, it = lower_bound(b, b + m, a[i]) - b;
        if (it < m) d = b[it] - a[i];
        it--;
        if (it >= 0) d = min(d, a[i] - b[it]);
        ans = max(ans, d);
    }
    printf("%lld\n", ans);
}
