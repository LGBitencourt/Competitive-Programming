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

int n, m, q, total;
pii edges[MAX];
vector<int> adj[MAX];
bool rm[MAX], visited[MAX];
int rm_index[MAX], ans[MAX], pai[MAX], sz[MAX];

void dfs (int v) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i]])
            dfs (adj[v][i]);
}

int find (int v) {
    if (pai[v] == 0) return v;
    return pai[v] = find (pai[v]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap (a, b);
    pai[a] = b, sz[b] += sz[a];
    return true;
}

int main() {
    scanf (" %d %d", &n, &m);
    for (int i = 1; i <= m; i++) 
        scanf (" %d %d", &edges[i].ff, &edges[i].ss);
    scanf (" %d", &q);
    for (int i = 1; i <= q; i++) {
        scanf (" %d", &rm_index[i]);
        rm[rm_index[i]] = true;
    }
    for (int i = 1; i <= m; i++) {
        if (rm[i]) continue;
        adj[edges[i].ff].pb(edges[i].ss);
        adj[edges[i].ss].pb(edges[i].ff);
        join (edges[i].ff, edges[i].ss);
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs (i), total++;
    int qi, x, y;
    for (int i = q; i > 0; i--) {
        qi = rm_index[i];
        x = edges[qi].ff, y = edges[qi].ss;
        ans[i] = total;
        if (join (x, y)) total--;
    }
    for (int i = 1; i <= q; i++)
        printf ("%d%c", ans[i], (i == q) ? '\n' : ' ');
}

