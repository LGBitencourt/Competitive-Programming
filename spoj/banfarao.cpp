#include <bits/stdc++.h>
#define debug(args...) fprintf (args...)
#define MAX 400005
using namespace std;

int seg[MAX], size[MAX];

void update (int l, int r, int i, int v, int n) {
    if (i < l || i > r) return;
    if (l == r) {
        seg[n] = v, size[n] = 1;
        return;
    }
    update (l, (l+r)/2, i, v, 2*n);
    update (((l+r)/2)+1, r, i, v, 2*n+1);
    seg[n] = seg[2*n] + seg[2*n+1];
    size[n] = size[2*n] + size[2*n+1];
}

int query (int l, int r, int x, int y, int n) {
    if (l > y || r < x) return 0;
    if (l >= x && r <= y) return seg[n];
    return query (l, (l+r)/2, x, y, 2*n)
        + query (((l+r)/2)+1, r, x, y, 2*n+1);
}

int main () {
    int t, n, v, q, x, y;
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf (" %d", &v);
            update (0, n-1, i, v, 1);
        }
        scanf (" %d", &q);
        while (q--) {
            scanf (" %d %d", &x, &y);
            printf ("%d\n", query (0, n-1, x-1, y-1, 1));
        }
    }
}

