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
/////////////////0123456789
const int MAX  = 1005;
const int MAXM = 100005;
const int modn = 1000000007;

bool seen[MAX], seen_c[MAX], used[MAX];
vector<int> adj[MAX], adj_c[MAX];
int low[MAX], d[MAX], st[MAX], comp[MAX];
int n, m, x, y, w, t, sn, qtd_c, total;
pii e[MAXM];

void connected (int u) {
    seen_c[u] = true;
    for (int v : adj_c[u])
        if (!seen_c[v])
            connected (v);
}

void dfs (int u) {
    seen[u] = true;
    low[u] = d[u] = t++;
    st[sn++] = u;
    for (int v : adj[u]) {
        if (!seen[v]) {
            dfs(v);
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
        qtd_c++;
    }
}

int main() {
    while (scanf (" %d %d", &n, &m) != EOF) {
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            adj_c[i].clear();
            seen[i] = seen_c[i] = false;
            comp[i] = i;
        }
        t = total = sn = qtd_c = 0;
        scanf (" %d %d %d", &x, &y, &w);
        for (int i = 1; i < m; i++) {
            scanf (" %d %d %d", &x, &y, &w);
            x--, y--;
            adj_c[x].pb(y);
            adj_c[y].pb(x);
            adj[x].pb(y);
            e[i].ff = x, e[i].ss = y;
            if (w == 2)
                adj[y].pb(x);
        }
        bool c = true;
        connected(0);
        for (int i = 0; i < n && c; i++)
            if (!seen_c[i])
                c = false;
        if (!c) {
            printf ("*\n");
            continue;
        }
        for (int i = 0; i < n; i++)
            if (!seen[i]) dfs(i);
        if (qtd_c == 1) {
            printf ("-\n");
            continue;
        }
        for (int i = 0; i < m; i++) {
            x = comp[e[i].ff], y = comp[e[i].ss];
            if (x == y) continue;
            total++;
        }
        printf ("%c\n", (total >= qtd_c) ? '1' : '2');
    }
}

