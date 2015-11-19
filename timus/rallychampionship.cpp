#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

typedef pair<int, int> pii;

vector<pii> adj[105];
bool visited[105];
int m, n, s, a, b, w, l, ma;

int cycle (int v, int p) {
    if (visited[v]) return 1;
    visited[v] = true;
    int ans = 0;
    for (int i = 0; i < adj[v].size(); i++)
        if (adj[v][i].ss != p)
            ans += cycle (adj[v][i].ss, v);
    return ans;
}

int c () {
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        if (visited[i]) continue;
        ans += cycle(i, 0);
    }
    return ans;
}

void dfs (int v, int path) {
    visited[v] = true;
    if (path > ma) ma = path, l = v;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i].ss])
            dfs (adj[v][i].ss, path + adj[v][i].ff);
}

int pl () {
    for (int i = 0; i < 105; i++)
        visited[i] = false;

    ma = 0;
    for (int i = 1; i <= m; i++) {
        if (visited[i]) continue;
        dfs (i, 0);
        for (int i = 0; i <= 101; i++)
            visited[i] = false;
        dfs (l, 0);
    }
    return ma;
}

int main () {
    scanf (" %d %d %d", &m, &n, &s);
    for (int i = 0; i < 105; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++) {
        scanf (" %d %d %d", &a, &b, &w);
        adj[a].push_back(pii(w, b));
        adj[b].push_back(pii(w, a));
    }

    if (c() > 0 || pl() >= s)
        printf ("YES\n");
    else printf ("NO\n");

}
