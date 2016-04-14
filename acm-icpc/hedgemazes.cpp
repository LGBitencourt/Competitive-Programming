#include <bits/stdc++.h>
#define MAXN 10005
using namespace std;

vector<int> adj[MAXN];
bool seen[MAXN];
int low[MAXN], d[MAXN], uf[MAXN], sz[MAXN], t;

int find (int v) {
    if (uf[v] == -1) return v;
    return uf[v] = find (uf[v]);
}

void join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap (a, b);
    uf[a] = b;
    sz[b] += sz[a];
}

void dfs (int u, int p) {
    seen[u] = true;
    low[u] = d[u] = t++;
    for (int v : adj[u]) {
        if (!seen[v]) {
            dfs (v, u);
            if (low[v] > d[u]) join (u, v);
            low[u] = min (low[u], low[v]);
        } else if (v != p) low[u] = min (low[u], d[v]);
    }
}

int main () {
    int n, m, q, x, y;
    while (scanf (" %d %d %d", &n, &m, &q) && n != 0) {
        for (int i = 0; i <= n; i++)
            adj[i].clear(), seen[i] = false, uf[i] = -1, sz[i] = 1;
        t = 0;
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &x, &y);
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++)
            if (!seen[i]) dfs(i, 0);
        while (q--) {
            scanf (" %d %d", &x, &y);
            printf ("%c\n", find (x) == find (y) ? 'Y' : 'N');
        }
        printf("-\n");
    }
}

