#include <bits/stdc++.h>

using namespace std;

bool marked[100005], cats[100005];
vector<int> adj[100005];
int n, m, r = 0;

void dfs (int v, int s) {
    marked[v] = true;
    if (s > m) return;
    if (!cats[v]) s = 0;
    if (adj[v].size() == 1 && v != 1) r++;
    for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
        if (!marked[*it])
            dfs(*it, s + cats[*it]);
}

int main () {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> cats[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, cats[1]);
    cout << r << '\n';
}
