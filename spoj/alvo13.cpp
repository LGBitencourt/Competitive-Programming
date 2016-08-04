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
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 100004;
const int modn = 1000000007;

int c, t;
ll r[MAXN];

int bb (int i, int j, ll v) {
    if (i == j) return i;
    int m = (i + j)/2;
    if (r[m] < v) return bb (m + 1, j, v);
    return bb (i, m, v);
}

int main() {
    scanf (" %d %d", &c, &t);
    for (int i = 0; i < c; i++) {
        scanf (" %d", &r[i]);
        r[i] *= r[i];
    }
    sort (r, r + c);
    ll p = 0;
    for (int i = 0; i < t; i++) {
        ll x, y;
        scanf (" %lld %lld", &x, &y);
        ll v = (x*x) + (y*y);
        if (v <= r[c-1])
            p += (ll) c - bb (0, c-1, v);
    }
    printf ("%lld\n", p);
}

