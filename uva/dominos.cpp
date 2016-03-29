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
const int MAX = 100004;
const int modn = 1000000007;

int n, m, scc, sn, t;
int low[MAX], d[MAX], 
    comp[MAX], st[MAX], incomp[MAX];
vector<int> adj[MAX];
pii edge[MAX];
bool seen[MAX], used[MAX];

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
        do {
            a = st[--sn];
            comp[a] = u;
            d[a] = INT_MAX;
        } while (a != u);
    }
}

int main() {
    int tc, x, y;
    scanf (" %d", &tc);
    while (tc--) {
        for (int i = 0; i <= n; i++) {
            seen[i] = used[i] = false;
            adj[i].clear();
            incomp[i] = 0;
            comp[i] = i;
        }
        scc = 0;
        t = sn = 0;
        scanf (" %d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &x, &y);
            adj[x].pb(y);
            edge[i] = pii (x, y);
        }
        for (int i = 1; i <= n; i++)
            if (!seen[i])
                dfs(i);
        for (int i = 0; i < m; i++) {
            if (comp[edge[i].ff] != comp[edge[i].ss])
                incomp[comp[edge[i].ss]]++;
        }
        for (int i = 1; i <= n; i++) 
            if (!used[comp[i]] && incomp[comp[i]] == 0)
                scc++, used[comp[i]] = true;
        printf ("%d\n", scc);
    }
}

