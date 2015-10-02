#include <cstdio>
#include <vector>

using namespace std;

bool visited[10005];
vector<int> adj[10005];

void dfs(int v) {
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i]]) {
            visited[adj[v][i]] = true;
            dfs(adj[v][i]);
        }
}

int main () {
    int n;
    scanf(" %d", &n);
    for(int i = 0;  i <= n; i++)
        visited[i] = false;
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        adj[a].push_back(b);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (!visited[i]) {
            printf("N\n");
            return 0;
        }
    printf("S\n");
}
