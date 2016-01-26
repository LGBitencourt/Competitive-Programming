#include <bits/stdc++.h>
#define MAX 400005
using namespace std;
typedef long long ll;

ll seg[MAX], lazy[MAX];

void propagate (int l, int r, int n) {
    seg[n] += (r - l + 1) * ((ll) lazy[n]);
    if (l != r) {
        lazy[2*n] += lazy[n];
        lazy[(2*n) + 1] += lazy[n];
    }
    lazy[n] = 0;
}

void update (int l, int r, int x, int y, ll v, int n) {
    propagate (l, r, n);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        seg[n] += (r - l + 1) * ((ll) v);
        if (l != r) {
            lazy[2*n] += v;
            lazy[(2*n) + 1] += v;
        }
        return;
    }
    update (l, (l+r)/2, x, y, v, 2*n);
    update (((l+r)/2) + 1, r, x, y, v, (2*n) + 1);
    if (l != r)
        seg[n] = seg[2*n] + seg[(2*n) + 1];
}

ll query (int l, int r, int x, int y, int n) {
    propagate (l, r, n);
    if (l >= x && r <= y) return seg[n];
    if (r < x || l > y) return 0;
    return query (l, (l+r)/2, x, y, 2*n)
        + query (((l+r)/2) + 1, r, x, y, (2*n) + 1);
}

int main () {
    int c, n, q, x, y, t;
    ll v;
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d %d", &n, &q);
        memset (seg, 0, sizeof seg);
        memset (lazy, 0, sizeof lazy);
        for (int i = 0; i < q; i++) {
            scanf (" %d %d %d", &c, &x, &y);
            if (c == 0) {
                scanf (" %lld", &v);
                update (0, n-1, x-1, y-1, v, 1);
            } else {
                printf ("%lld\n", query (0, n-1, x-1, y-1, 1));
            }
        }
    }
}
