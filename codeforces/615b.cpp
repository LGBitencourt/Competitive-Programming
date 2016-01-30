#include <bits/stdc++.h>
#define MAX 200005
using namespace std;
typedef long long ll;

//ll dp[MAX];
ll mdp[MAX];
vector<int> adj[MAX];

ll dp (int i) {
    if (mdp[i] != 0) return mdp[i];
    mdp[i] = 1;
    for (int v = 0; v < adj[i].size (); v++)
        if (adj[i][v] < i)
            mdp[i] = max (mdp[i], dp (adj[i][v]) + 1);
    return mdp[i];
}

int main () {
    ios::sync_with_stdio (false);
    int n, m;
    ll ans = -1LL;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back (y);
        adj[y].push_back (x);
    }
    for (int i = 1; i <= n; i++) {
        /*dp[i] = 1;
        for (int v = 0; v < adj[i].size(); v++)
            if (adj[i][v] < i)
                dp[i] = max (dp[i], dp[adj[i][v]] + 1);
        ans = max (ans, dp[i] * (ll) adj[i].size ());*/
        ans = max (ans, dp(i) * (ll) adj[i].size ());
    }
    cout << ans << endl;
}
