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
const int MAXN = 200004;
const int modn = 1000000007;

int n, c;
// int mdp[MAXN][2];
int dp[2][2];
int v[MAXN];

/*int dp(int i, int f) {
    if (i == n) return 0;
    if (mdp[i][f] != -1) return mdp[i][f];
    if (f) return mdp[i][f] = max(dp(i + 1, 0) + v[i], dp(i + 1, 1));
    else return mdp[i][f] = max(dp(i + 1, 1) - v[i] - c, dp(i + 1, 0));
}*/

int main() {
    while (scanf(" %d %d", &n, &c) != EOF) {
        // memset(mdp, -1, sizeof mdp);
        for (int i = 0; i < n; i++)
            scanf(" %d", &v[i]);
        //printf("%d\n", dp(0, 0));
        dp[1][0] = dp[1][1] = 0;
        for (int i = n-1; i >= 0; i--) {
            dp[0][0] = max(dp[1][1] - v[i] - c, dp[1][0]);
            dp[0][1] = max(dp[1][0] + v[i], dp[1][1]);
            dp[1][0] = dp[0][0], dp[1][1] = dp[0][1];
        }
        printf("%d\n", dp[0][0]);
    }
}

