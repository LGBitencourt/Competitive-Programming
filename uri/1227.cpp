#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 205;
const int modn = 1000000007;

int n, a, b, c;
vector<int> adj[MAX];
set<int> path;
bool seen[MAX], p[MAX];
int d[MAX];

bool find_path(int u, int c) {
    p[u] = true;
    if (u == c) {
        path.insert(u);
        return true;
    }
    for (int v : adj[u]) {
        if (p[v]) continue;
        if (find_path(v, c)) {
            path.insert(v);
            return true;
        }
    }
    return false;
}

void dfs (int u, int t) {
    seen[u] = true;
    d[u] = t;
    for (int v : adj[u])
        if (!seen[v]) dfs(v, t+1);
}

int main () {
    while (scanf (" %d %d %d %d", &n, &a, &b, &c) != EOF) {
        for (int i = 0; i <= n; i++) adj[i].clear(), seen[i] = false, p[i] = false;
        path.clear();
        for (int i = 1; i < n; i++) {
            int x, y;
            scanf (" %d %d", &x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for (int i = 0; i <= n; i++) seen[i] = false;
        path.insert(b);
        find_path(b, c);
        dfs(a, 0);
        int mi, cur = inf;
        for (int i : path)
            if (d[i] < cur) cur = d[i], mi = i;
        for (int i = 0; i <= n; i++) seen[i] = false;
        dfs(c, 0);
        printf("%lf\n", ((double) d[mi])/d[b]);
    }
}
