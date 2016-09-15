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
const int MAXN = 100005;
const int modn = 1000000007;

int v[MAXN], seg[4*MAXN];
pii r[MAXN];

void update(int l, int r, int v, int i, int n) {
    if (l > i || r < i) return;
    if (l == r) {
        seg[n] = v;
        return;
    }
    update(l, (l + r)/2, v, i, 2*n);
    update(((l + r)/2) + 1, r, v, i, 2*n + 1);
    seg[n] = max(seg[2*n], seg[2*n + 1]);
}

int query(int l, int r, int x, int y, int n) {
    if (l > y || r < x) return -1;
    if (l >= x && r <= y) return seg[n];
    return max(query(l, (l + r)/2, x, y, 2*n),
            query(((l + r)/2) + 1, r, x, y, 2*n + 1));
}

int main() {
    int n;
    int ans = 0;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        r[i] = pii(x, y);
    }
    sort(r, r + n);
    for (int i = 0; i < n; i++) {
        update(0, n - 1, r[i].ss, i, 1);
        v[i] = r[i].ff;
    }
    for (int i = 0; i < n; i++) {
        int d = upper_bound(v, v + n, v[i]) - v;
        if (d >= n) ans++;
        else if (r[i].ss >= query(0, n - 1, d, n, 1)) ans++;
    }
    printf("%d\n", ans);
}

