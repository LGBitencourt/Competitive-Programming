#include <bits/stdc++.h>
#define MAX 1000005
#define ff first
#define ss second
#define pb push_back
using namespace std;
typedef pair<int, int> pii;

bool visited[MAX];
int pai[MAX], sz[MAX];
// ff peso ss vertice
vector<pii> adj[MAX];

struct no {
    int x, y, w;
} ed[MAX];

void dfs (int v) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i].ss])
            dfs (adj[v][i].ss);
}

int find (int v) {
    if (pai[v] == -1) return v;
    return pai[v] = find (pai[v]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap (a, b);
    sz[b] += sz[a], pai[a] = b;
    return true;
}

bool compare (no a, no b) {
    if (a.w != b.w) return a.w < b.w;
    return a.x < b.x;
}

int main () {
    int n, m;
    while (scanf (" %d %d", &n, &m) && n != 0) {
        for (int i = 0; i < MAX; i++)
            visited[i] = false, sz[i] = 0, pai[i] = -1, adj[i].clear();

        int x, y, w;
        for (int i = 0; i < m; i++) {
            scanf (" %d %d %d", &x, &y, &w);
            no a;
            a.x = x, a.y = y, a.w = w;
            ed[i] = a;
        }
        sort (ed, ed+m, compare);

        int ma = 0;
        for (int i = 0; i < m; i++) {
            if (join (ed[i].x, ed[i].y)) {
                ma = max (ma, ed[i].w);
                adj[ed[i].x].pb (pii (ed[i].w, ed[i].y));
            }
        }
        dfs (0);
        bool f = false;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                printf ("IMPOSSIBLE\n");
                f = true;
                break;
            }
        }
        if (f) continue;
        printf ("%d\n", ma);
    }
}
