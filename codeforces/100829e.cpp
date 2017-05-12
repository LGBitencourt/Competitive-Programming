#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 1123456;

int n, ans;
int v[MAXN];
bool seen[MAXN];
vector<int> adj[MAXN];
map<int, vector<int>> y;

void dfs(int u) {
    seen[u] = true;
    ans = max(ans, u);
    for (int x : adj[u])
        if (!seen[x]) dfs(x);        
}

int main() {
    while (scanf(" %d", &n) && n != 0) {
        y.clear();
        ans = 0;
        for (int i = 0; i < MAXN; i++)
            adj[i].clear(), seen[i] = false;
        for (int i = 0; i < n; i++) {
            scanf(" %d", v + i);
            if (v[i] > 1000000) continue;
            y[i - v[i]].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            if (v[i] > 1000000) continue;
            for (int x : y[v[i] + i]) {
                adj[x].push_back(i);
                adj[i].push_back(x);
            }
        }
        dfs(0);
        printf("%d\n", ans);
    }
}

