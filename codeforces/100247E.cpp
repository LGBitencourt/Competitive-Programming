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

int mais[MAXN];
char osmais[MAXN];
vector<int> adj[MAXN];
set<int> st;

void dfs(int u, bool status) {
    if (osmais[u] == '0') osmais[u] = status ? '+' : '-';
    for (int v : adj[u])
        dfs(v, osmais[u] == '+');
}

int solve(int u) {
    if (!adj[u].size()) return mais[u] = osmais[u] == '+';
    int ans = 0;
    for (int v : adj[u])
        ans += solve(v);
    return mais[u] = (ans == adj[u].size());
}

void print(int u) {
    if (mais[u]) st.insert(u);
    else {
        for (int v : adj[u])
            print(v);
    }
}

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %c", &osmais[i]);
    for (int i = 1; i < n; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        a--, b--;
        adj[a].pb(b);
    }
    dfs(0, osmais[0] == '+');
    solve(0);
    print(0);
    printf("%d\n", st.size());
    for (int a : st) printf("%d ", a + 1);
    puts("");
}

