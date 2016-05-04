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
const int MAX = 200005;
const int modn = 1000000007;

int k, w;
int a, b, n, cmp;
int uf[MAX], sz[MAX];
map<int, int> m;
set<pii> e;
set<int> adj[MAX];

int find (int v) {
    if (uf[v] == -1) return v;
    return uf[v] = find (uf[v]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap (a, b);
    sz[b] += sz[a];
    uf[a] = b;
    return true;
}

int compress (int v) {
    auto f = m.find(v);
    if (f != m.end()) v = f->second;
    else {
        m[v] = n;
        v = n++;
        adj[v].clear();
    }
    return v;
}

int main() {
    while (scanf (" %d %d", &k, &w), k != 0) {
        m.clear();
        e.clear();
        for (int i = 0; i < MAX; i++)
            uf[i] = -1, sz[i] = 1;

        bool can = true;
        n = 0;

        for (int i = 0; i < w; i++) {
            scanf (" %d %d", &a, &b);
            a = compress(a), b = compress(b);
            e.insert(mp(min(a, b), max(a, b)));
        }

        for (auto i : e) {
            a = i.ff, b = i.ss;
            adj[a].insert(b), adj[b].insert(a);
            if (!join (a, b)) {
                a = find (a);
                if (sz[a] != k)
                    can = false;
            }
        }

        for (int i = 0; i < n; i++)
            if (adj[i].size() > 2) can = false;

        printf ("%c\n", (can) ? 'Y' : 'N');
    }
}

