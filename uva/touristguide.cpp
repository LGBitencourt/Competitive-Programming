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
bool seen[MAX], cut[MAX];
int low[MAX], d[MAX];
int t, tc = 1, c, nf, root;
map<string, int> m;
map<int, string> mi;

void dfs (int u, int p) {
    seen[u] = true;
    low[u] = d[u] = t++;
    for (int v : adj[u]) {
        if (!seen[v]) {
            if (u == 0) nf++;
            dfs (v, u);
            if (low[u] >= d[u]) {
                cut[u] = true;
            }
            low[u] = min (low[u], low[v]);
        } else if (v != p) low[u] = min (low[u], d[v]);
    }
}

int main() {
    int n, e, x, y;
    char name[35];
    while (scanf (" %d", &n) && n != 0) {
        if (tc > 1) putchar ('\n');
        for (int i = 0; i <= n; i++) {
            adj[i].clear();
            seen[i] = cut[i] = false;
        }
        t = c = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %s", name);
            m[name] = i;
            mi[i] = name;
        }
        scanf (" %d", &e);
        for (int i = 0; i < e; i++) {
            scanf (" %s", name);
            x = m.find(name)->second;
            scanf (" %s", name);
            y = m.find(name)->second;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        dfs (0, -1);
        cut[0] = (nf > 1);
        for (int i = 0; i < n; i++) c += cut[i];
        printf ("City map #%d: %d camera(s) found\n", tc++, c);
        for (int i = 0; i < n; i++) {
            if (cut[i]) {
                printf ("%s%c", (mi.find(i)->second).c_str(), (c == 1) ? '\n' : ' ');
                c--;
            }
        }
    }
}

