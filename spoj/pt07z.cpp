#include <cstdio>
#include <vector>

using namespace std;

int ma, n, l;
bool visited[10005];
vector<int> adj[10005];

void dfs(int v, int m) {
    visited[v] = true;
    if (m > ma) ma = m, l = v;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i]])
            dfs(adj[v][i], m + 1);
}

int main () {
    scanf(" %d", &n);
    for (int i = 0; i <= n; i++)
        visited[i] = false;
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 0; i <= n; i++)
        visited[i] = false;
    dfs(l, 0);
    printf("%d\n", ma);
}
