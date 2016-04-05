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
const int MAX = 20004;
const int MAXM = 50004;
const int modn = 1000000007;

bool seen[MAX], used[MAX];
int low[MAX], d[MAX], st[MAX], comp[MAX];
int in[MAX], out[MAX];
vector<int> adj[MAX];
int n, m, sn, t, ain, aout, c;
pii e[MAXM];

void dfs (int u) {
    seen[u] = true;
    low[u] = d[u] = t++;
    st[sn++] = u;
    for (int v : adj[u]) {
        if (!seen[v]) {
            dfs (v);
            low[u] = min (low[u], low[v]);
        } else low[u] = min (low[u], d[v]);
    }
    if (low[u] >= d[u]) {
        int a;
        do {
            a = st[--sn];
            comp[a] = u;
            d[a] = inf;
        } while (a != u);
        c++;
    }
}

int main () {
    int tc, x, y, ans;
    scanf (" %d", &tc);
    while (tc--) {
        scanf (" %d %d", &n, &m);
        for (int i = 0; i <= n; i++)
            adj[i].clear(), seen[i] = false, used[i] = false,
                comp[i] = i, in[i] = 0, out[i] = 0;
        ain = aout = c = 0;
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &x, &y);
            x--, y--;
            e[i].ff = x, e[i].ss = y;
            adj[x].pb(y);
        }
        for (int i = 0; i < n; i++)
            if (!seen[i]) dfs (i);
        for (int i = 0; i < m; i++) {
            if (comp[e[i].ss] == comp[e[i].ff]) continue;
            in[comp[e[i].ss]]++, out[comp[e[i].ff]]++;
        }
        for (int i = 0; i < n; i++) {
            if (used[comp[i]]) continue;
            if (in[comp[i]] == 0) ain++;
            if (out[comp[i]] == 0) aout++;
            used[comp[i]] = true;
        }
        if (c == 1) printf ("0\n");
        else printf ("%d\n", max (ain, aout));
    }
}
