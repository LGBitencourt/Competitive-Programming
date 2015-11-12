#include <bits/stdc++.h>

#define ff first
#define ss second
#define MAX 100005

using namespace std;

typedef pair<int, int> pii;

int n, f;
vector<pii> adj[MAX];
bool visited[MAX];
int sz[MAX];

int path (int v) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i].ss])
            sz[v] += adj[v][i].ff + dfs (adj[v][i].ss);
    return sz[v];
}

int main () {
    scanf (" %d %d", &n, &f);

    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf (" %d %d %d", &a, &b, &c);
        adj[a].push_back(pii(c, b));
        adj[b].push_back(pii(c, a));
    }
    path (1);
    for (int i = 1; i <= n; i++)
        printf ("%d %d\n", i, sz[i]);
}
