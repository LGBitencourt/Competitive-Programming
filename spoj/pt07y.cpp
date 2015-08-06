#include <cstdio>
#include <vector>

using namespace std;

vector<int> adj[10005];
int marked[10005];

void dfs(int v) {
    marked[v] = 1;
    for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
        if (!marked[*it])
            dfs(*it);
}

int main() {
    int n, m, x, y, ok = 1;

    scanf(" %d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf(" %d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(y);

    for (int i = 1; i <= n && ok; i++)
        if (!marked[i]) ok = 0;

    if (m == (n - 1) && ok) printf("YES\n");
    else printf("NO\n");

}
