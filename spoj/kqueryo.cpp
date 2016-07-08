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
const int MAXN = 200004;
const int modn = 1000000007;

struct node {
    vector<int> v;
    node () {};
    node (vector<int> a) { v = a; }
    node (vector<int> a, vector<int> b) {
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) v.pb(a[i++]);
            else v.pb(b[j++]);
        }
        while (i < a.size()) v.pb(a[i++]);
        while (j < b.size()) v.pb(b[j++]);
    };
};

node seg[MAXN];

void update (int l, int r, int i, int n, int x) {
    if (i < l || i > r) return;
    if (l == r) {
        vector<int> v;
        v.pb(x);
        seg[n] = node(v);
        return;
    }
    update (l, (l+r)/2, i, 2*n, x);
    update (((l+r)/2)+1, r, i, 2*n+1, x);
    seg[n] = node (seg[2*n].v, seg[2*n + 1].v);
}

int query (int l, int r, int x, int y, int n, int k) {
    if (l > y || r < x) return 0;
    if (x <= l && y >= r) return seg[n].v.end() - 
        upper_bound(seg[n].v.begin(), seg[n].v.end(), k);
    return query (l, (l+r)/2, x, y, 2*n, k) +
        query (((l+r)/2)+1, r, x, y, 2*n+1, k);
}

int main () {
    int n, q, last_ans = 0;
    scanf (" %d", &n);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf (" %d", &x);
        update (1, n, i, 1, x);
    }
    scanf (" %d", &q);
    while (q--) {
        int a, b, c, i, j, k;
        scanf (" %d %d %d", &a, &b, &c);
        i = a ^ last_ans;
        j = b ^ last_ans;
        k = c ^ last_ans;
        if (i < 1) i = 1;
        if (j > n) j = n;
        if (i > j) { printf("0\n"); last_ans = 0; continue; }
        last_ans = query(1, n, i, j, 1, k);
        printf("%d\n", last_ans);
    }
}

