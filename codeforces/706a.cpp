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
const int MAXN = 1004;
const int modn = 1000000007;

pii l[MAXN];
int v[MAXN];

int main() {
    int a, b, n;
    scanf (" %d %d", &a, &b);
    scanf (" %d", &n);
    double ans = inf;
    for (int i = 0; i < n; i++)
        scanf (" %d %d %d", &l[i].ff, &l[i].ss, &v[i]);
    for (int i = 0; i < n; i++) {
        double d = sqrt ((a - l[i].ff)*(a - l[i].ff) + (b - l[i].ss)*(b - l[i].ss));
        double t = d/v[i];
        if (t < ans - eps) ans = t;
    }
    printf ("%lf\n", ans);
}

