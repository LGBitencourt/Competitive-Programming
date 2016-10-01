#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int n;
ll v[MAXN];
// ll mdp[MAXN][2];
ll mdp[2][2];

ll dp(int i, bool b) {
    if (i == n) return 0;
    if (mdp[i][b] != -1) return mdp[i][b];
    ll ans = dp(i + 1, false);
    if (!b) ans = max(ans, dp(i + 1, true) + v[i]);
    return mdp[i][b] = ans;
}

int main() {
    int t;
    scanf(" %d", &t);
    for (int tc = 1; tc <= t; tc++) {
        //memset(mdp, -1, sizeof mdp);
        scanf(" %lld", &n);
        for (int i = 0; i < n; i++)
            scanf(" %lld", &v[i]);
        mdp[1][0] = mdp[1][1] = 0;
        //printf("Case %d: %lld\n", tc, dp(0, false));
        for (int i = n - 1; i >= 0; i--) {
            mdp[0][0] = max(mdp[1][0], mdp[1][1]);
            mdp[0][1] = v[i] + mdp[1][0];
            mdp[1][0] = mdp[0][0], mdp[1][1] = mdp[0][1];
        }
        printf("Case %d: %lld\n", tc, max(mdp[0][0], mdp[0][1]));
    }
}

