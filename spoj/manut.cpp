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
const int MAX = 504;
const int modn = 1000000007;

int nf, t;
bool seen[MAX], cut[MAX];
int low[MAX], d[MAX];
vector<int> adj[MAX];


void dfs (int u, int p) {
    seen[u] = true;
    low[u] = d[u] = t++;
    bool any = false;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (!seen[v]) {
            if (u == 1) nf++;

            dfs (v, u);

            if (low[v] >= d[u]) cut[u] = true;

            low[u] = min (low[u], low[v]);
        } else if (v != p) low[u] = min (low[u], d[v]);
    }
}

int main() {
    int n, m, u, v, tc = 1;
    bool space;
    while (scanf (" %d %d", &n, &m), n != 0) {
        t = 0, nf = 0;
        for (int i = 1; i <= n; i++) {
            seen[i] = cut[i] = false;
            adj[i].clear();
        }
        space = false;
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &u, &v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs(1, 0);
        cut[1] = (nf > 1);
        printf ("Teste %d\n", tc++);
        for (int i = 1; i <= n; i++)
            if (cut[i]) {
                if (space) printf (" %d", i);
                else printf ("%d", i), space = true;
            }
        if (!space) printf ("nenhum");
        printf("\n\n");
    }
}

