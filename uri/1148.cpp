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

bool seen[MAX];
int low[MAX], d[MAX], st[MAX], comp[MAX];
int t, sn, n, m, x, y, w;
vector<int> adj[MAX];
pii e[MAX];

int dijkstra (int u, int v) {

}

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
            d[u] = INT_MAX;
        } while (u != a);
    }
}

int main() {
    while (scanf (" %d %d", &n, &m), n != 0) {
        for (int i = 0; i < m; i++) {
            scanf (" %d %d %d", 
        }
    }
}

