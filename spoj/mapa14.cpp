#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> adj[100005];
bool visited[100005];

long long int total, cm, n;

void dfs(int v) {
    visited[v] = true;
    cm++;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i]])
            dfs(adj[v][i]);
}

int main () {
    scanf(" %lld", &n);
    for (int i = 1; i <= n; i++) visited[i] = false;
    for (int i = 1; i < n; i++) {
        int x, y, e;
        scanf(" %d %d %d", &x, &y, &e);
        if (e) continue;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    total = n * (n - 1)/2;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            cm = 0;
            dfs(i);
            total -= cm * (cm - 1)/2;
        }
    }
    printf("%lld\n", total);
}
