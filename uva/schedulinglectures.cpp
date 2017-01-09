#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 1004;

int L, C, n;
int t[MAXN];
int mdp[MAXN][505];

int cost(int t_l) {
    if (t_l == 0) return 0;
    if (t_l >= 1 && t_l <= 10) return -C;
    return (t_l - 10) * (t_l - 10);
}

bool can(int idx, int l, int r) {
    while (idx < n) {
        if (l == 0) return false;
        if (r < t[idx]) l--, r = L;
        else r -= t[idx++];
    }
    return true;
}

int dp(int i, int l, int r) {
    if (l == 0 || r < 0 || !can(i, l, r)) return inf;
    if (i == n) return cost(r);
    if (mdp[i][r] != -inf) return mdp[i][r];
    int ans = dp(i, l - 1, L) + cost(r);
    ans = min(ans, dp(i + 1, l, r - t[i]));
    return mdp[i][r] = ans;
}

int main() {
    int tc = 0;
    while (scanf(" %d", &n), n != 0) {
        int sum = 0;
        scanf(" %d %d", &L, &C);
        for (int i = 0; i < n; i++)
            scanf(" %d", t + i);
        int tl = L, mi = 1, idx = 0;
        while (idx < n) {
            if (tl >= t[idx]) tl -= t[idx++];
            else mi++, tl = L;
        }
        for(int i = 0; i < 1004; i++)
            for(int j = 0; j < 504; j++)
                mdp[i][j] = -inf;
        if (tc) putchar('\n');
        printf("Case %d:\n", ++tc);
        printf("Minimum number of lectures: %d\n", mi);
        printf("Total dissatisfaction index: %d\n", dp(0, mi, L));
    }
}

