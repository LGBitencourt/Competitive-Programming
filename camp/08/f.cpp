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
typedef pair<double,int> pdi;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int n, a, b;
pdi d[MAXN], e[MAXN];

bool cmp(pdi x, pdi y) {
    if (x.ff != y.ff) return x.ff > y.ff;
    return x.ss < y.ss;
}

int main() {
    scanf (" %d %d %d", &n, &a, &b);
    for (int i = 0; i < n; i++) {
        int ai, bi;
        scanf (" %d %d", &ai, &bi);
        d[i].ff = ((double) a)/ai;
        e[i].ff = ((double) b)/bi;
        d[i].ss = e[i].ss = i;
    }
    if (n == 1) {
        printf("%lf\n", max(d[0].ff, e[0].ff));
        return 0;
    }
    sort (d, d + n, cmp);
    sort (e, e + n, cmp);
    double ma = 0;
    if (d[0].ss != e[0].ss) {
        printf("%lf\n", d[0].ff + e[0].ff);
        return 0;
    }
    ma = max (ma, d[0].ff + e[1].ff);
    ma = max (ma, d[1].ff + e[0].ff);
    printf("%lf\n", ma);
    return 0;
}

