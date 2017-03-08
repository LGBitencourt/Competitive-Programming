#include <bits/stdc++.h>

#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int modn = 1000000007;
const int MAXN = 112345;

int c[MAXN];
ll dp[MAXN][2];
bool seen[MAXN];
vector<int> adj[MAXN];

void dfs(int v) {

    dp[v][0] = 1 - c[v];
    dp[v][1] = c[v];

    seen[v] = true;

    for (int u : adj[v]) {
        if (!seen[u]) {
            ll init_n = dp[v][0];
            ll init_t = dp[v][1];
            dp[v][0] = dp[v][1] = 0;
            dfs(u);

            dp[v][0] = (dp[v][0] + (init_n * dp[u][1] % modn)) % modn;
            dp[v][1] = (dp[v][1] + (init_t * dp[u][1] % modn)) % modn;

            dp[v][1] = (dp[v][1] + (init_t * dp[u][0] % modn)) % modn;
            dp[v][1] = (dp[v][1] + (init_n * dp[u][1] % modn)) % modn;

            dp[v][0] = (dp[v][0] + (init_n * dp[u][0] % modn)) % modn;
        }
    }
}

int main() {
    int n;
    scanf(" %d", &n);
    for (int i = 0; i < n - 1; i++) {
        int x;
        scanf(" %d", &x);
        adj[x].pb(i + 1), adj[i + 1].pb(x);
    }

    for (int i = 0; i < n; i++)
        scanf(" %d", c + i);
    dfs(0);
    printf("%lld\n", dp[0][1] % modn);
}

