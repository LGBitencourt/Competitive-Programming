#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 11234;

int t, n, m, ans;
int in[MAXN][MAXN], dp[MAXN][MAXN];

int main() {
    scanf(" %d", &t);
    while (t--) {
        ans = 0;
        scanf(" %d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf(" %d", &in[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0) dp[i][j] = in[i][j];
                else if (in[i][j] == 0) dp[i][j] = 0;
                else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        printf("%d\n", ans);
    }
}

