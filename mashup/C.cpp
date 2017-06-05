#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 200004;

int degree[MAXN], d[MAXN];
bool mark[MAXN];
vector<int> adj[MAXN];

int main() {
    int c, p, x, l;
    scanf(" %d %d %d %d", &c, &p, &x, &l);
    for (int i = 0; i < p; i++) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
        degree[v]++, degree[u]++;
        d[v]++, d[u]++;
    }
    mark[l] = true, d[l] = 0;
    queue<int> q;
    q.push(l);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            d[v]--;
            if (!mark[v] && d[v] <= degree[v] / 2) {
                mark[v] = true;
                q.push(v);
            }
        }
    }
    printf("%s\n", mark[x] ? "leave" : "stay");
}

