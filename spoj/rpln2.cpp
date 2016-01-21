#include <bits/stdc++.h>
using namespace std;

int seg[500005];

void update (int l, int r, int i, int v, int n) {
    if (i < l || i > r) return;
    if (l == r) {
        seg[n] = v;
        return;
    }
    update (l, (l+r)/2, i, v, 2*n);
    update (((l+r)/2)+1, r, i, v, (2*n)+1);
    seg[n] = min (seg[2*n], seg[(2*n)+1]);
}

int query (int x, int y, int l, int r, int n) {
    if (x >= l && y <= r) return seg[n];
    if (x > r || y < l) return INT_MAX;
    return min (query (x, (x+y)/2, l, r, 2*n),
            query (((x+y)/2)+1, y, l, r, (2*n)+1));
}

int main () {
    int t, n, q;
    scanf (" %d", &t);
    for (int tc = 1; tc <= t; tc++) {
        scanf (" %d %d", &n, &q);
        for (int i = 0; i < n; i++) {
            int v;
            scanf (" %d", &v);
            update (0, n-1, i, v, 1);
        }
        printf ("Scenario #%d:\n", tc);
        for (int i = 0; i < q; i++) {
            int l, r;
            scanf (" %d %d", &l, &r);
            printf ("%d\n", query (0, n-1, l-1, r-1, 1));
        }
    }
}

