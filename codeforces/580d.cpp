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
const int MAX = 500005;
const int modn = 1000000007;

int n, m, k;
ll a[20];
ll p[20][20], mdp[20][MAX];

ll dp (int i, int mask) {
    if (__builtin_popcount(mask) >= m) return 0;
    if (mdp[i][mask] != -1) return mdp[i][mask];
    ll ans = 0;
    for (int j = 1; j <= n; j++) {
        if (mask&((1 << j))) continue;
        ans = max (ans, a[j] + p[i][j] + dp (j, (mask|(1 << j))));
    }
    return mdp[i][mask] = ans;
}

int main() {
    ios::sync_with_stdio (false);
    int x, y;
    memset (mdp, -1, sizeof mdp);
    ll c;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= k; i++) {
        cin >> x >> y >> c;
        p[x][y] = c;
    }
    cout << dp (0, 0) << endl;
}

