#include <cstdio>
#include <vector>

using namespace std;

bool visited[100005];
vector<int> adj[100005];

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i]])
            dfs(adj[v][i]);
}

int main () {
    int n, m, c = 0;
    scanf(" %d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            c++, dfs(i);
    printf("%d\n", c);
}
