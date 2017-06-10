#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 2234;

int mdp[MAXN][MAXN][25];
int sum[MAXN];
int n;

int dp(int i, int l, int d) {
    if (i == n) {
        int s = sum[i] - sum[l];
        if (s % 10 < 5) return s - (s % 10);
        else return s + (10 - (s % 10));
    }
    if (mdp[i][l][d] != -1) return mdp[i][l][d];
    int ans = dp(i + 1, l, d);
    int s = sum[i] - sum[l];
    int now;
    if (s % 10 < 5) now = s - (s % 10);
    else now = s + (10 - (s % 10));
    if (d) ans = min(ans, now + dp(i + 1, i, d - 1));
    return mdp[i][l][d] = ans;
}

int main() {
    int d;
    scanf(" %d %d", &n, &d);
    memset(mdp, -1, sizeof mdp);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf(" %d", &x);
        sum[i] = x + sum[i-1];
    }
    printf("%d\n", dp(1, 0, d));
}

