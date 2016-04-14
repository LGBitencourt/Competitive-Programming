#include <bits/stdc++.h>
#define MAX 105
using namespace std;

int dist[MAX];
vector<int> adj[MAX];

void dfs (int u, int d) {
    for (int v : adj[u])
        if (dist[v] < d + 1)
           dist[v] = d+1, dfs (v, dist[v]);
}

int main () {
    int n, s, p, q, mi, tc = 1;
    while (scanf (" %d", &n) && n != 0) {
        for (int i = 0; i <= n; i++)
            adj[i].clear(), dist[i] = 0;
        scanf (" %d", &s);
        while (scanf (" %d %d", &p, &q) && p != 0)
            adj[p].push_back(q);
        dfs (s, 0);
        mi = 1;
        for (int i = 2; i <= n; i++)
            if (dist[i] > dist[mi]) mi = i;
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", tc++, s, dist[mi], mi);
    }
}
