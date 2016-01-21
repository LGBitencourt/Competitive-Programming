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
    if (x > r || y < l) return
}
