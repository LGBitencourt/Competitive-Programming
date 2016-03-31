#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 1000000000;
////////////////0123456789
const int MAX = 501*501;
const int MAXF = 501;
const int modn = 1000000007;

struct aifox {
    int x, y, w;
    aifox () {};
    aifox (int a, int b, int c) : x(a), y(b), w(c) {}
} edge[MAX];

bool seen[MAXF];
int low[MAXF], d[MAXF], st[MAXF], comp[MAXF], dist[MAXF], instac[MAXF];
int t, sn, n, m, x, y, w, k, russo;
vector<int> adj[MAXF];
vector<pii> adj_comp[MAXF];
priority_queue<pii> pq;

void dijkstra (int u) {
    dist[u] = 0;
    pq.push (pii(0, u));
    while (!pq.empty()) {
        pii aux = pq.top();
        pq.pop();
        for (pii p : adj_comp[aux.ss]) {
            if (dist[p.ss] > dist[aux.ss] + p.ff) {
                dist[p.ss] = dist[aux.ss] + p.ff;
                pq.push (pii(-dist[p.ss], p.ss));
            }
        }
    }
}

void dfs (int u) {
    seen[u] = true;
    low[u] = d[u] = t++;
    st[sn++] = u;
    instac[u] = 1;
    for (int v : adj[u]) {
        if (!seen[v]) {
            dfs (v);
            low[u] = min (low[u], low[v]);
        } else if (instac[v]) low[u] = min (low[u], d[v]);
    }
    if (low[u] >= d[u]) {
        int a;
        do {
            a = st[--sn];
            comp[a] = russo;
            instac[a] = 0;
        } while (u != a);
        russo++;
    }
}

int main() {
    while (scanf (" %d %d", &n, &m) && n != 0) {
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            adj_comp[i].clear();
            seen[i] = false;
        }
        sn = t = russo = 0;

        for (int i = 0; i < m; i++) {
            scanf (" %d %d %d", &x, &y, &w);
            edge[i] = aifox(x, y, w);
            adj[x].pb(y);
        }

        for (int i = 1; i <= n; i++)
            if (!seen[i]) dfs (i);

        for (int i = 0; i < m; i++) {
            int a, b, c;
            a = comp[edge[i].x];
            b = comp[edge[i].y];
            c = edge[i].w;
            if (a == b)
                continue;
            adj_comp[a].pb (pii (c, b));
        }

        scanf (" %d", &k);
        while (k--) {
            scanf (" %d %d", &x, &y);
            x = comp[x];
            y = comp[y];
            if (x == y) {
                printf ("0\n");
                continue;
            }
            for (int i = 0; i < russo; i++) dist[i] = inf;
            dijkstra (x);
            if (dist[y] == inf)
                printf ("Nao e possivel entregar a carta\n");
            else
                printf ("%d\n", dist[y]);
        }
        printf ("\n");
    }
}

