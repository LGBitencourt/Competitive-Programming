#include <bits/stdc++.h>
using namespace std;

int seg[500005];
int N, K, X, Y;
char c;

void update (int l, int r, int i, int v, int n) {
    if (i < l || i > r) return;
    if (l == r) {
        seg[n] = v;
        return;
    }
    update (l, (l+r)/2, i, v, 2*n);
    update (((l+r)/2)+1, r, i, v, (2*n)+1);
    seg[n] = seg[2*n]*seg[(2*n) + 1];
}

int query (int l, int r, int x, int y, int n) {
    if (l >= x && r <= y) return seg[n];
    if (r < x || l > y) return 1;
    return query (l, (l+r)/2, x, y, 2*n)
        * query (((l+r)/2) + 1, r, x, y, (2*n) + 1);
}

void update(int i, int v) {
    if (v < 0) v = -1;
    else if (v > 0) v = 1;
    else v = 0;
    update(0, N-1, i, v, 1);
}
int query (int l, int r) {
    return query (0, N-1, l, r, 1);
}

int main () {
    while (scanf (" %d %d", &N, &K) != EOF) {
        memset (seg, 1, sizeof seg);
        for (int i = 0; i < N; i++) {
            int a;
            scanf (" %d", &a);
            update (i, a);
        }
        for (int i = 0; i < K; i++) {
            scanf (" %c %d %d", &c, &X, &Y);
            if (c == 'C') update (X-1, Y);
            else if (c == 'P') {
                int a = query (X-1, Y-1);
                if (a > 0) putchar ('+');
                else if (a < 0) putchar ('-');
                else putchar ('0');
            }
        }
        putchar ('\n');
    }
}
