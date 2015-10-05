#include <iostream>
#include <vector>

using namespace std;

typedef long long int lli;

vector<int> adj[50005];

lli total;
int k, n;

void dfs(int v, int path, int p) {
    if (path == k) {
        total++;
        return;
    }
    for (int i = 0; i < adj[v].size(); i++)
        if (adj[v][i] != p)
            dfs(adj[v][i], path + 1, v);
}

int main () {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        dfs(i, 0, i);
    cout << total/2 << '\n';
}
