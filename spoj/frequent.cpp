#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int a[MAX];
struct node {
    int m, l, r;
    node () {}
    node (int i) {
        m = l = r = 1;
    }
};
node seg[4*MAX];

void build (int l, int r, int n) {
    if (l == r) {
        seg[n] = node (1);
        return;
    }
    int m = (l + r)/2;
    build (l, m, 2*n);
    build (m + 1, r, 2*n + 1);
    if (a[m] == a[m + 1]) {
        seg[n].l = seg[2*n].l + seg[2*n + 1].l * (a[l] == a[m]);
        seg[n].r = seg[2*n + 1].r + seg[2*n].r * (a[r] == a[m + 1]);
        int tmp = seg[2*n].r + seg[2*n + 1].l;
        seg[n].m = max (tmp, max (seg[2*n].m, seg[2*n + 1].m));
    } else {
        seg[n].l = seg[2*n].l;
        seg[n].r = seg[2*n + 1].r;
        seg[n].m = max (seg[2*n].m, seg[2*n + 1].m);
    }
}

int query (int l, int r, int x, int y, int n) {
    if (x == l && y == r) return seg[n].m;
    int m = (l + r)/2;
    if (y <= m) return query (l, m, x, y, 2*n);
    if (x > m) return query (m + 1, r, x, y, 2*n + 1);
    int ql = query (l, m, x, m, 2*n);
    int qr = query (m + 1, r, m + 1, y, 2*n + 1);
    if (a[m] == a[m+1]) {
        int tmp = min (seg[2*n].r, m - x + 1) + min (seg[2*n + 1].l, y - m);
        return max (tmp, max (qr, ql));
    } else {
        return max (ql, qr);
    }
}

int main () {
    int n, q, x, y;
    while (scanf (" %d", &n) && n) {
        scanf (" %d", &q);
        for (int i = 0; i < n; i++)
            scanf (" %d", &a[i]);
        build (0, n - 1, 1);
        for (int i = 0; i < q; i++) {
            scanf (" %d %d", &x, &y);
            printf ("%d\n", query (0, n-1, x-1, y-1, 1));
        }
    }
}
