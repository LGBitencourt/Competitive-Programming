#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 504;

int n, m;
int H[MAXN][MAXN], d[MAXN][MAXN];

int x[] = {1, -1, 0, 0},
    y[] = {0, 0, 1, -1};

void clr() {
    for (int i = 0; i <= n; i++)
        for (int j = 0; j<= m; j++)
            d[i][j] = inf;
}

bool valid(pii v, int t, int h) {
    if (v.ff < 1 || v.ff > n || v.ss < 1 || v.ss > m) return false;
    if (d[v.ff][v.ss] < inf) return false;
    if (h + 1 + t >= H[v.ff][v.ss]) return false;
    return true;
}

bool bfs(int t) {
    clr();
    queue<pii> q;
    if (t < H[1][1]) {
        q.push(pii(1, 1));
        d[1][1] = 0;
    }
    while (q.size()) {
        pii v = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii c = pii(v.ff + x[i], v.ss + y[i]);
            if (valid(c, t, d[v.ff][v.ss])) {
                q.push(c);
                d[c.ff][c.ss] = d[v.ff][v.ss] + 1;
            }
        }
    }
    return d[n][m] < inf;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf(" %d", &H[i][j]);
    int l = 0, h = 1000006;
    while (l != h) {
        int m = (l + h + 1) / 2;
        if (bfs(m)) l = m;
        else h = m - 1;
    }
    if (!bfs(0)) printf("-1\n");
    else printf("%d\n", l);
}

