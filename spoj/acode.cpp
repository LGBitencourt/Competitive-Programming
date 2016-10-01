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
const int MAXN = 5004;
const int modn = 1000000007;

int n;
int s[MAXN];
ll dp[MAXN];
// ll mdp[MAXN];

/*ll dp(int i) {
    if (i == n) return 1;
    if (i > n || s[i] == 0) return 0;
    if (mdp[i] != -1) return mdp[i];
    if ((s[i] == 2 && s[i + 1] > 6) || (s[i] > 2))
        return mdp[i] = dp(i + 1);
    else
        return mdp[i] = dp(i + 1) + dp(i + 2);
}*/

int main() {
    char buff[5005];
    while (scanf(" %s", buff), buff[0] != '0') {
        // memset(mdp, -1, sizeof mdp);
        n = strlen(buff);
        for (int i = 0; buff[i] != 0; i++)
            s[i] = buff[i] - '0';
        dp[2] = 1;
        if (s[n-1] != 0) dp[1] = 1;
        else dp[1] = 0;
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == 0) dp[0] = 0;
            else if (10 * s[i] + s[i + 1] <= 26
                    && 10 * s[i] + s[i + 1] >= 10)
                dp[0] = dp[1] + dp[2];
            else dp[0] = dp[1];
            dp[2] = dp[1];
            dp[1] = dp[0];
        }
        printf("%lld\n", dp[0]);
        //printf("%lld\n", dp(0));
    }
}

