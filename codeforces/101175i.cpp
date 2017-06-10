#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

pii c[MAXN];
int seg[4 * MAXN], sum[4 * MAXN];
struct e {
    int x, y0, y1, sign;
    e() {}
    e(int a, int b, int c, int s) {
        x = a, y0 = b, y1 = c, sign = s;
    }
    bool operator<(const e &o) const {
        return x < o.x;
    }
} edges[2 * MAXN];

void update(int l, int r, int x, int y, int n, int v) {
    if (l > y || r < x) return;
    if (l >= x && r <= y) {
        seg[n] += v;
    } else {
        int m = (l + r) / 2;
        update(l, m, x, y, 2 * n, v);
        update(m + 1, r, x, y, 2 * n + 1, v);
    }

    if (seg[n] > 0) sum[n] = r - l + 1;
    else sum[n] = sum[2 * n] + sum[2 * n + 1];
}

bool can(int k, int n) {
    int ed = 0, area = 0, lx = 0;
    for (int i = 0; i < n; i++) {
        int x1 = c[i].ff - k, x2 = c[i].ff + k, y1 = c[i].ss - k, y2 = c[i].ss + k;
        if (x2 >= -k && x1 <= k && y1 <= k && y2 >= -k) {
            printf("inter com mumia %d\n", i);
            printf("%d %d %d %d\n", max(x1, -k), min(x2, k), max(y1, -k), min(y2, k));
            edges[ed++] = e(max(x1, -k), max(y1, -k), min(y2, k), 1);
            edges[ed++] = e(min(x2, k), max(y1, -k), min(y2, k), -1);
            lx = min(lx, min(min(x2, k), max(x1, -k))) - 1;
        }
    }
    sort(edges, edges + ed);
    for (int i = 0; i < ed; i++) {
        e a = edges[i];
        area += sum[1] * (a.x - lx);
        lx = a.x;
        update(0, 300005, a.y0, a.y1, 1, a.sign);
    }
    printf("%d\n", area);
    return area < 4 * (k * k + k) + 1;
}

int main() {
    int n, tc = 1;
    while (scanf(" %d", &n), n != -1) {
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf(" %d %d", &x, &y);
            c[i] = pii(x, y);
        }
        /*int l = 0, r = inf;
        while (l != r) {
            int m = (r + l) / 2;
            if (can(m, n)) l = m;
            else r = m - 1;
        }*/
        //if (r == inf) printf("Case %d: never", tc++);
        //else printf("Case %d: %d\n", tc++, l);
        printf("%d\n", can(25, n));
    }
}

