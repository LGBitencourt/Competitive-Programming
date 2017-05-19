#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 10004;

int color[MAXN][2], cc = 1;
vector<int> adj[MAXN];

int dfs(int u, int c, int p) {
    color[u][0] = (c == -1 ? ++cc : c);

    for (int v : adj[u]) {
        if (v == p) continue;
        if (color[u][1] == -1)
            color[u][1] = dfs(v, -1, u);
        else dfs(v, color[u][0], u);
    }
    if (color[u][1] == -1) color[u][1] = color[p][0];
    return color[u][0];
}

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 1; i < n; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].pb(v), adj[v].pb(u);
        color[u][0] = color[u][1] = 
            color[v][0] = color[v][1] = -1;        
    }
    dfs(1, 1, -1);
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", color[i][0], color[i][1]);
}

