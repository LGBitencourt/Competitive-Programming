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
const int modn = 1000000007;

int in[MAX], out[MAX], comp[MAX];
int c_in[MAX], c_out[MAX];
int c;
bool seen[MAX];
vector<int> adj[MAX];

void dfs (int u) {
    seen[u] = true;
    comp[u] = c;
    for (int i = 0; i < adj[u].size(); i++)
        if (!seen[adj[u][i]])
            dfs (adj[u][i]);
}

int main () {
    int tc, n, m, x, y, ans;
    scanf (" %d", &tc);
    while (tc--) {
        ans = c = 0;
        scanf (" %d %d", &n, &m);
        for (int i = 0; i <= n; i++) {
            c_in[i] = c_out[i] = in[i] = out[i] = 0;
            comp[i] = -1;
            seen[i] = false;
            adj[i].clear();
        }
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &x, &y);
            adj[x].pb(y);
            adj[y].pb(x);
            out[x]++, in[y]++;
        }
        for (int i = 1; i <= n; i++)
            if (!seen[i]) dfs (i), c++;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) c_in[comp[i]]++;
            if (out[i] == 0) c_out[comp[i]]++;
        }
        for (int i = 0; i < c; i++)
            ans += max (c_in[i], c_out[i]);
        printf ("%d\n", ans);
    }
}
