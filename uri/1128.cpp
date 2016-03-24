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
const int MAX = 2005;
const int modn = 1000000007;

int low[MAX], d[MAX], st[MAX], comp[MAX];
int scc, t, n, m, sn;
vector<int> adj[MAX];
bool seen[MAX];

void dfs (int u) {
    seen[u] = true;
    st[sn++] = u;
    d[u] = low[u] = t++;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], d[v]);
    }
    if (low[u] >= d[u]) {
        int a;
        scc++;
        do {
            a = st[--sn];
            comp[a] = u;
            d[a] = INT_MAX;
        } while (a != u);
    }
}

int main() {
    int x, y, w;
    while (scanf (" %d %d", &n, &m), n != 0) {
        for (int i = 0; i <= n; i++) {
            seen[i] = false;
            adj[i].clear();
            comp[i] = i;
        }
        scc = t = sn = 0;
        for (int i = 0; i < m; i++) {
            scanf (" %d %d %d", &x, &y, &w);
            adj[x].pb(y);
            if (w == 2) adj[y].pb(x);
        }
        for (int i = 1; i <= n; i++)
            if (!seen[i])
                dfs(i);
        printf ("%d\n", (scc == 1) ? 1 : 0);
    }
}

