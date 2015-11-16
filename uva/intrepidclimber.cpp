#include <bits/stdc++.h>

#define ff first
#define ss second
#define MAX 100005

using namespace std;

typedef pair<int, int> pii;

int n, f;
vector<pii> adj[MAX];
bool marked[MAX], forbid[MAX];
int sz[MAX], degree[MAX], pai[MAX];

int path (int v, int p) {
    if (degree[v] == 1 && v != 1) return 0;
    sz[v] = 0;
    for (int i = 0; i < adj[v].size(); i++)
        if (adj[v][i].ss != p && !forbid[adj[v][i].ss])
            sz[v] += path (adj[v][i].ss, v) + adj[v][i].ff;
    return sz[v];
}

void remove_parent () {
    queue<int> q;
    for (int i = 2; i <= n; i++)
        if (degree[i] == 1)
            q.push(i);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x != 1 && marked[x]) continue;
        degree[pai[x]]--, forbid[x] = true;
        if (degree[pai[x]] == 1)
            q.push(pai[x]);
    }
}

int solve (int v, int p) {
    if (degree[v] == 1 && v != 1) return 0;
    int ans = INT_MAX;
    for (int i = 0; i < adj[v].size(); i++)
        if (adj[v][i].ss != p && !forbid[adj[v][i].ss])
            ans = min (ans, sz[v] - sz[adj[v][i].ss] - adj[v][i].ff + solve(adj[v][i].ss, v));
    return ans;
}

int main () {
    while (scanf (" %d %d", &n, &f) != EOF) {
        for (int i = 0; i <= n; i++)
            sz[i] = degree[i] = pai[i] = marked[i] = forbid[i] = 0, adj[i].clear();

        for (int i = 1; i < n; i++) {
            int a, b, c;
            scanf (" %d %d %d", &a, &b, &c);
            adj[a].push_back(pii(c, b));
            adj[b].push_back(pii(c, a));
            pai[b] = a, degree[a]++, degree[b]++;
        }
        for (int i = 0; i < f; i++) {
            int x;
            scanf (" %d", &x);
            marked[x] = true;
        }
        remove_parent();
        path (1, 0);
        printf ("%d\n", solve (1, 0));
    }
}
