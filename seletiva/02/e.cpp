#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define right robson
#define left lkjads

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 104;

typedef enum{up, left, down, right} dir;
dir d = right;

char in[MAXN*MAXN];
char ans[MAXN][MAXN];

pii go_left(pii x) {
    d = left;
    return pii(x.x - 1, x.y);
}

pii go_right(pii x) {
    d = right;
    return pii(x.x + 1, x.y);
}

pii go_up(pii x) {
    d = up;
    return pii(x.x, x.y + 1);
}

pii go_down(pii x) {
    d = down;
    return pii(x.x, x.y - 1);
}

pii step(pii c, char nd) {
    if (d == up) {
        if (nd == 'F') return go_up(c);
        if (nd == 'B') return go_down(c);
        if (nd == 'R') return go_right(c);
        if (nd == 'L') return go_left(c);
    }

    if (d == down) {
        if (nd == 'F') return go_down(c);
        if (nd == 'B') return go_up(c);
        if (nd == 'R') return go_left(c);
        if (nd == 'L') return go_right(c);
    }

    if (d == left) {
        if (nd == 'F') return go_left(c);
        if (nd == 'B') return go_right(c);
        if (nd == 'R') return go_up(c);
        if (nd == 'L') return go_down(c);
    }

    if (d == right) {
        if (nd == 'F') return go_right(c);
        if (nd == 'B') return go_left(c);
        if (nd == 'R') return go_down(c);
        if (nd == 'L') return go_up(c);
    }
}

int main() {
    int t;
    scanf(" %d", &t);
    printf("%d\n", t);
    while (t--) {
        int n, minn, maxn, m;
        n = m = maxn = 0; minn = inf;
        d = right;
        vector<pii> l;
        l.pb(pii(0, 0));
        scanf(" %s", in);
        for (int i = 0; in[i] != 0; i++) {
            pii ns = step(l[i], in[i]);
            m = max(m, abs(ns.x));
            maxn = max(maxn, ns.y);
            minn = min(minn, ns.y);
            l.pb(ns);
        }
        m += 2, n = (maxn - minn + 3);
        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = '#';
        for (pii v : l) ans[n - (v.y - minn + 1) - 1][v.x] = '.';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf("%c", ans[i][j]);
            printf("\n");
        }
    }
}

