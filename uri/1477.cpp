#include <bits/stdc++.h>
#define debug(args...) //fprintf(stderr, args)
#define MAX 4000005
using namespace std;

struct s {
    int h, e, r;
};

struct s operator + (const s &a, const s &b) {
    struct s c;
    c.h = a.h + b.h, c.e = a.e + b.e, c.r = a.r + b.r;
    return c;
}

s seg[MAX];
int lazy[MAX];

void build (int l, int r, int i, int n) {
    if (i < l || i > r) return;
    if (l == r) {
        seg[n].h = 1, seg[n].e = 0, seg[n].r = 0;
        return;
    }
    build (l, (l+r)/2, i, 2*n);
    build (((l+r)/2)+1, r, i, 2*n + 1);
    seg[n] = seg[2*n] + seg[2*n + 1];
}

void propagate (int l, int r, int n) {
    s a;
    for (int i = 0; i < lazy[n] % 3; i++)
        a.h = seg[n].r, a.e = seg[n].h, a.r = seg[n].e, seg[n] = a;
    if (l != r) lazy[2*n] += lazy[n], lazy[2*n + 1] += lazy[n];
    lazy[n] = 0;
}

void update (int l, int r, int x, int y, int n) {
    propagate (l, r, n);
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        s a;
        a.h = seg[n].r, a.e = seg[n].h, a.r = seg[n].e, seg[n] = a;
        debug ("UPDATE %d %d %d\n", a.h, a.e, a.r);
        debug ("UPDATE 2 %d %d %d\n", seg[n].h, seg[n].e, seg[n].r);
        if (l != r) lazy[2*n] += 1, lazy[2*n + 1] += 1;
        return;
    }
    update (l, (l+r)/2, x, y, 2*n);
    update (((l+r)/2)+1, r, x, y, 2*n+1);
    seg[n] = seg[2*n] + seg[2*n + 1];
}

s query (int l, int r, int x, int y, int n) {
    debug ("QUERY %d %d\n", l, r);
    propagate (l, r, n);
    if (x <= l && y >= r) return seg[n];
    s a;
    a.h = 0, a.e = 0, a.r = 0;
    if (x > r || l > y) return a;
    return query (l, (l+r)/2, x, y, 2*n)
        + query (((l+r)/2)+1, r, x, y, 2*n + 1);
}

int main () {
    int n, m;
    char c;
    while (scanf (" %d %d", &n, &m) != EOF) {
        memset (lazy, 0, sizeof lazy);
        for (int i = 0; i < n; i++) build (0, n-1, i, 1);
        int x, y;
        for (int i = 0; i < m; i++) {
            scanf (" %c %d %d", &c, &x, &y);
            if (c == 'C') {
                s a = query (0, n-1, x-1, y-1, 1);
                printf ("%d %d %d\n", a.h, a.e, a.r);
            } else {
                update (0, n-1, x-1, y-1, 1);
            }
        }
    }
}
