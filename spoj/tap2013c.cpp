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
const int MAXN = 30004;

int n, s;
ll m[MAXN], mdp[MAXN];
vector<int> adj[MAXN];

ll dfs(int i) {
    if (i == n) return 1LL;
    if (m[i] != -1) return m[i];
    ll ans = 0;
    for (int v : adj[i])
        ans += dfs(v);
    return m[i] = ans;
}

ll dp(int i) {
    if (i == n) return 1LL;
    if (mdp[i] != -1) return mdp[i];
    ll ans = 0;
    for (int v : adj[i])
        ans = max(ans, dp(v));
    ans += dfs(i);
    return mdp[i] = ans;
}

int main() {
    scanf(" %d %d", &n, &s);
    for (int i = 0; i < s; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        adj[x].pb(y);
    }
    memset(m, -1, sizeof m);
    memset(mdp, -1, sizeof mdp);
    dfs(1);
    printf("%lld\n", dp(1));
}

