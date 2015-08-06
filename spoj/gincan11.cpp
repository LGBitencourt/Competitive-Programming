#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[1005];
int marked[1005];
int n, m, x, y, t = 0;

void dfs(int v) {
    marked[v] = 1;
    for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
        if (!marked[*it])
            dfs(*it);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (!marked[i])
            t++, dfs(i);
    }

    printf("%d\n", t);
}
