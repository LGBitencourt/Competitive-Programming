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
const int MAX = 104;
const int modn = 1000000007;

vector<int> adj[MAX];
bool seen[MAX];
int low[MAX], d[MAX];
int t, tc = 1, nf, root;
map<string, int> m;
map<int, string> mi;
set<string> nm;

void dfs (int u, int p) {
    seen[u] = true;
    low[u] = d[u] = t++;
    int nf = 0;
    bool any = false;
    for (int v : adj[u]) {
        if (!seen[v]) {
            nf++;
            dfs (v, u);
            if (low[v] >= d[u]) any = true;
            low[u] = min (low[u], low[v]);
        } else if (v != p) low[u] = min (low[u], d[v]);
    }
    if (u == root && nf > 1) nm.insert (mi[u]);
    else if (u != root && any) nm.insert (mi[u]);
}

int main() {
    int n, e, x, y;
    char name[35];
    while (scanf (" %d", &n) && n != 0) {
        if (tc > 1) putchar ('\n');
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            seen[i] = false;
        }
        t = 0;
        nm.clear(), m.clear(), mi.clear();
        for (int i = 0; i < n; i++) {
            scanf (" %s", name);
            m[name] = i;
            mi[i] = name;
        }
        scanf (" %d", &e);
        for (int i = 0; i < e; i++) {
            scanf (" %s", name);
            x = m[name];
            scanf (" %s", name);
            y = m[name];
            adj[x].pb(y);
            adj[y].pb(x);
        }
        for (int i = 0; i < n; i++) {
            if (!seen[i]) {
                root = i;
                dfs (i, -1);
            }
        }
        printf ("City map #%d: %d camera(s) found\n", tc++, nm.size());
        int s = nm.size();
        for (set<string>::iterator it = nm.begin(); it != nm.end(); ++it)
            printf ("%s\n", (*it).c_str());
    }
}

