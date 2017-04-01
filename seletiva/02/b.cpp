#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;

int n;
int v[20];
int mdp[20][3605][3605];
int memo[20][3605];

int dp(int i, int w, int t, int T) {
    if (t >= T) return min(3600, t) - T;
    if (i == n) return inf;
    if (mdp[i][w][t] != -1) return mdp[i][w][t];
    int ans = dp(i + 1, w, t, T);
    if (w) ans = min(ans, dp(i, w - 1, t + v[i], T));
    return mdp[i][w][t] = ans;
}

int coin(int i, int w) {
    if (w == 0) return 0;
    if (i == n || w < 0) return inf;
    if (memo[i][w] != -1) return memo[i][w];
    return memo[i][w] = min(coin(i, w - v[i]) + 1, coin(i + 1, w));
}

int main() {
    int tt;
    scanf(" %d", &tt);
    while (tt--) {
        for (int i = 0; i < 17; i++)
            for (int j = 0; j < 3605; j++) {
                for (int k = 0; k < 3605; k++)
                    mdp[i][j][k] = -1;
                memo[i][j] = -1;
            }
        int t;
        scanf(" %d %d", &n, &t);
        for (int i = 0; i < n; i++)
            scanf(" %d", v + i);
        if (coin(0, t) < inf) printf("%d 0\n", coin(0, t));
        else {
            int l = 0, h = 4000;
            while (l != h) {
                int m = (l + h) / 2;
                int ans = dp(0, m, 0, t);
                if (ans < inf) h = m;
                else l = m + 1;
            }
            printf("%d %d\n", l, dp(0, l, 0, t));
        }
    }
}

