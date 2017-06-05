#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define list uhae

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 212345;

int n, m;
int f[MAXN], sz[MAXN], degree[MAXN];
pii edges[MAXN];
vector<pii> list[MAXN];

int find(int v) {
    if (f[v] == v) return v;
    return f[v] = find(f[v]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return false;
    if (sz[u] > sz[v]) swap(u, v);
    f[v] = u;
    sz[v] += sz[u];
    return true;
}

void clr() {
    for (int i = 0; i < MAXN; i++) {
        degree[i] = 0;
        sz[i] = 0;
        f[i] = i;
        list[i].clear();
    }
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        clr();
        scanf(" %d %d", &n, &m);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf(" %d %d", &u, &v);
            edges[i] = pii(u, v);
            degree[u]++, degree[v]++;
        }
        for (int i = 0; i < m; i++) {
            pii e = edges[i];
            list[min(degree[e.ff], degree[e.ss])].pb(e);
        }
        int cc = n;
        stack<int> q;
        for (int i = n - 1; i >= 0; i--) {
            q.push(cc - 1);
            for (pii e : list[i])
                if (join(e.ff, e.ss)) cc--;
        }
        while (q.size()) {
            int c = q.top();
            q.pop();
            printf("%d%c", c, q.empty() ? '\n' : ' ');
        }
    }
}

