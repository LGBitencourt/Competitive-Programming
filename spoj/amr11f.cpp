#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 523;

int n, f, m, vx = 0, q;
map<pii, int> v_id;
set<int> bb[MAXN];
int d[MAXN][MAXN];

void floydwarshall() {
    for (int k = 0; k < vx; k++)
        for (int i = 0; i < vx; i++)
            for (int j = 0; j < vx; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

pii find_next(int bi, int fi) {
    int u, v;
    if (bb[bi].find(fi) != bb[bi].end()) u = fi;
    else {
        auto x = bb[bi].lower_bound(fi);
        x--;
        u = *x;
    }
    auto p = bb[bi].upper_bound(fi);
    v = (p == bb[bi].end()) ? u : *p;
    return pii(u, v);
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        vx = 0;
        for (int i = 0; i < MAXN; i++)
            bb[i].clear();
        v_id.clear();
        memset(d, inf, sizeof d);
        scanf(" %d %d %d", &n, &f, &m);
        for (int i = 0; i < n; i++)
            v_id[pii(i, 0)] = vx++;
        for (int i = 0; i < n; i++) {
            d[i][(i + 1) % n] = 
                d[(i + 1) % n][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            int bi, fi, bj, fj, t, u, w;
            scanf(" %d %d %d %d %d", &bi, &fi, &bj, &fj, &t);
            bi--, fi--, bj--, fj--;
            bb[bi].insert(fi);
            bb[bj].insert(fj);
            if (!v_id[pii(bi, fi)]) v_id[pii(bi, fi)] = vx++;
            if (!v_id[pii(bj, fj)]) v_id[pii(bj, fj)] = vx++;
            u = v_id[pii(bi, fi)], w = v_id[pii(bj, fj)];
            d[u][w] = d[w][u] = t;
        }

        for (int i = 0; i < n; i++) {
            int l = 0;
            for (int v : bb[i]) {
                int u, w;
                u = v_id[pii(i, l)], w = v_id[pii(i, v)];
                d[u][w] = d[w][u] = v - l;
                l = v;
            }
            bb[i].insert(0);
        }

        for (int i = 0; i < vx; i++)
            d[i][i] = 0;
        floydwarshall();

        scanf(" %d", &q);
        while (q--) {
            int bi, fi, bj, fj;
            scanf(" %d %d %d %d", &bi, &fi, &bj, &fj);
            bi--, fi--, bj--, fj--;
            int u, w, ans = inf;
            pii c1, c2;
            c1 = find_next(bi, fi);
            c2 = find_next(bj, fj);

            for(int i = 0; i < 4; i++) {
                int a, b;
                a = (i&1) ? c1.ff : c1.ss;
                b = (i&2) ? c2.ff : c2.ss;
                u = v_id[pii(bi, a)];
                w = v_id[pii(bj, b)];
                ans = min(ans, d[u][w] + abs(a - fi) + abs(b - fj));
            }

            printf("%d\n", bi != bj ? ans : min(ans, abs(fi - fj)));
        }
    }
}

