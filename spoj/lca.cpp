#include <bits/stdc++.h>
#define MAX 16005
#define debug(args...) fprintf (stderr, args)
using namespace std;

int height[MAX], last[MAX], tree[MAX], seg[MAX];
bool visited[MAX];
vector<int> adj[MAX];
int idx = 0;

void dfs (int v, int h) {
    visited[v] = true;
    height[idx] = h, last[v] = idx, tree[idx++] = v;
    for (int i = 0; i < adj[v].size(); i++) {
        if (!visited[adj[v][i]]) {
            dfs (adj[v][i], h+1);
            height[idx] = h, last[v] = idx, tree[idx++] = v;
        }
    }
}

void update (int l, int r, int i, int v, int n) {
    if (i < l || i > r) return;
    if (l == r) {
        seg[n] = v;
        return;
    }
    update (l, (l+r)/2, i, v, 2*n);
    update (((l+r)/2)+1, r, i, v, 2*n+1);
    seg[n] = (height[last[seg[2*n]]] < height[last[seg[2*n+1]]]) ? seg[2*n] : seg[2*n+1];
}

int query (int l, int r, int x, int y, int n) {
    if (l >= x && r <= y) return seg[n];
    if (l > y || r < x) return INT_MAX;
    int v, w;
    v = query (l, (l+r)/2, x, y, 2*n);
    w = query (((l+r)/2)+1, r, x, y, 2*n+1);
    if (v == INT_MAX) return w;
    if (w == INT_MAX) return v;
    return (height[last[v]] < height[last[w]]) ? v : w;
}

int main () {
    int n, t;
    scanf (" %d", &t);
    for (int tc = 1; tc <= t; tc++) {
        idx = 0;
        for (int i = 0; i < MAX; i++)
            adj[i].clear(), visited[i] = false, height[i] = 0, last[i] = 0;
        scanf (" %d", &n);
        for (int i = 1; i <= n; i++) {
            int q, v;
            scanf (" %d", &q);
            for (int j = 0; j < q; j++) {
                scanf (" %d", &v);
                adj[i].push_back(v);
                adj[v].push_back(i);
            }
        }
        dfs (1, 0);
        for (int i = 0; i < idx; i++)
            update (0, idx-1, i, tree[i], 1);
        int q;
        printf ("Case %d:\n", tc);
        scanf (" %d", &q);
        while (q--) {
            int x, y;
            scanf (" %d %d", &x, &y);
            x = last[x], y = last[y];
            if (x > y) swap (x, y);
            printf ("%d\n", query (0, idx-1, x, y, 1));
        }
    }
}

