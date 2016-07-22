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

ll total;
ll ql, qc;

bool l[MAXN], c[MAXN];

int main() {
    ql = qc = 0;
    ll n, m;
    scanf (" %lld %lld", &n, &m);
    total = n*n;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf (" %d %d", &x, &y);
        x--, y--;
        qc = min (qc, n), ql = min(ql, n);
        if (!l[x] && !c[y]) {
            total -= 2*n - 1 - ql - qc;
            ql++, qc++;
        } else if (l[x] && !c[y]) {
            total -= n - ql;
            qc++;
        } else if (c[y] && !l[x]) {
            total -= n - qc;
            ql++;
        }
        if (total < 0) total = 0;
        printf("%lld%c", total, (i == m-1) ? '\n' : ' ');
        l[x] = c[y] = true;
    }
}

