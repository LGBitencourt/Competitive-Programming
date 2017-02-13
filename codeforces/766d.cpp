#include <bits/stdc++.h>
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 412345;

int n, m, q, e;
map<string, int> dic;
vector<int> adj[MAXN];
vector<pii> edges;
int uf[MAXN], sz[MAXN], to[MAXN], type[MAXN], from[MAXN], xr[MAXN];
bool valid[MAXN], seen[MAXN];

int find(int v) {
    if (uf[v] == -1) return v;
    return uf[v] = find(uf[v]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (sz[v] > sz[u]) swap(u, v);
    sz[u] += sz[v];
    uf[v] = u;
    return true;
}

void dfs(int u, int x) {
    seen[u] = true;
    xr[u] = x;
    for (int i : adj[u]) {
        int v = to[i];
        if (!seen[v])
            dfs(v, x ^ type[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dic[s] = i;
        uf[i] = -1, sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int t, u, v;
        string x, y;
        cin >> t >> x >> y;
        u = dic[x], v = dic[y];
        if (join(u, v)) {
            adj[u].pb(e);
            to[e] = v, type[e] = t - 1;
            valid[i] = true;
            e++;
            adj[v].pb(e);
            to[e] = u, type[e] = t - 1;
            e++;
        } else {
            from[e] = u, to[e] = v, type[e] = t - 1;
            edges.pb(pii(e++, i));
        }
    }

    for (int i = 0; i < n; i++)
        if (!seen[i])
            dfs(i, 0);

    for (pii p : edges) {
        int i, e;
        tie(e, i) = p;
        int u = from[e], v = to[e], t = type[e];
        if (xr[u] ^ xr[v] == t) valid[i] = true;
        else valid[i] = false;
    }
    
    for (int i = 0; i < m; i++)
        cout << ((valid[i]) ? "YES" : "NO") << endl;

    while (q--) {
        int u, v;
        string x, y;
        cin >> x >> y;
        u = dic[x], v = dic[y];
        if (find(u) != find(v)) cout << "3\n";
        else cout << (xr[u] ^ xr[v]) + 1 << endl;
    }
}

