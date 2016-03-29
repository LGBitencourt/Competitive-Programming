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
const int MAX = 50004;
const int modn = 1000000007;

bool bridge;
bool seen[MAX];
int t, root;
int d[MAX], low[MAX];
vector<int> adj[MAX];

void dfs (int u, int p) {
    seen[u] = true;
    d[u] = low[u] = t++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs (v, u);
            if (low[v] > d[u]) 
                bridge = true;
            low[u] = min (low[u], low[v]);
        } else if (v != p) low[u] = min (low[u], d[v]);
    }
}

int main() {
    int n, m, x, y;
    while (scanf (" %d %d", &n, &m), n != 0) {
        for (int i = 0; i <= n; i++) {
            seen[i] = false;
            adj[i].clear();
        }
        t = 0, root = 1, bridge = false;
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs (1, 0);
        printf ("%c\n", (bridge) ? 'N' : 'S');
    }
}

