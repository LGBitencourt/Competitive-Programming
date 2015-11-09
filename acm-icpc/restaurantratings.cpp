#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int lli;

int n;
lli mdp[35][17], memo[35][17][2];
int rt[17];

lli dp (int sum, int i) {
    if (sum <= 0) return 0;
    if (mdp[sum][i] != -1) return mdp[sum][i];
    if (i == n) return 1;
    lli ans = 0;
    for (int j = 0; j < 31; j++)
        ans += dp (sum - j, i + 1);
    return mdp[sum][i] = ans;
}

lli dp2 (int sum, int i, bool b) {
    if (sum == 0) return 1;
    if (sum < 0 || i == n) return 0;
    if (memo[sum][i][b] != -1) return memo[sum][i][b];
    lli ans = 0;
    for (int j = 0; j < 31; j++) {
        if (b && j > rt[i]) break;
        ans += dp2 (sum - j, i + 1, b && j == rt[i]);
    }
    return memo[sum][i][b] = ans;
}

int main () {
    while (scanf (" %d", &n), n != 0) {
        memset (mdp, -1, sizeof mdp);
        memset (memo, -1, sizeof memo);
        int sr = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf(" %d", &x);
            sr += x, rt[i] = x;
        }
        printf ("%lld\n", dp(sr, 0) + dp2(sr, 0, true));
    }
}
