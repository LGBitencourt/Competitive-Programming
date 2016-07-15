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

vector<int> seg[4*MAXN];
int v[MAXN];

void build (int l, int r, int n) {
    if (l == r) {
        seg[n].pb(v[l]);
        return;
    }
    build (l, (l+r)/2, 2*n);
    build (((l+r)/2) + 1, r, 2*n + 1);
    int i, j;
    i = j = 0;
    vector<int> aux;
    while (i < seg[2*n].size() && j < seg[2*n+1].size()) {
        if (seg[2*n][i] < seg[2*n+1][j]) aux.pb(seg[2*n][i++]);
        else aux.pb(seg[2*n+1][j++]);
    }
    while (i < seg[2*n].size()) aux.pb(seg[2*n][i++]);
    while (j < seg[2*n+1].size()) aux.pb(seg[2*n+1][j++]);
    if (aux.size() == 1) seg[n].pb(aux[0]);
    if (aux.size() > 1 && aux[0] != aux[1]) seg[n].pb(aux[0]);
    i = 1;
    for (i = 1; i < aux.size() - 1; i++)
        if (aux[i] != aux[i-1] && aux[i] != aux[i+1]) seg[n].pb(aux[i]);
    if (aux.size() > 1 && aux[i] != aux[i-1]) seg[n].pb(aux[i]);
}

int query (int l, int r, int x, int y, int n) {
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return seg[n].size();
    return query (l, (l+r)/2, x, y, 2*n) +
        query (((l+r)/2) + 1, r, x, y, 2*n + 1);
}

int main() {
    int n, q;
    scanf (" %d", &n);
    for (int i = 1; i <= n; i++)
        scanf (" %d", &v[i]);
    build(1, n, 1);
    scanf (" %d", &q);
    while (q--) {
        int x, y;
        scanf (" %d %d", &x, &y);
        printf("%d\n", y - x + 1 - query(1, n, x, y, 1));
    }
}

