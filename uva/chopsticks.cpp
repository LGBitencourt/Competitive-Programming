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
/////////////////0123456789
const int MAXN = 1005;
const int modn = 1000000007;

int K, n;
int c[5*MAXN];
int mdp[5*MAXN][MAXN];

bool cmp (int a, int b) { return a > b; }

int dp (int i, int k) {
    if (k == 0) return 0;
    if (i >= n-1) return modn;
    if (mdp[i][k] != -1) return mdp[i][k];
    int ans = dp(i + 1, k);
    if (i - 3*(K - k) > 0)
        ans = min(ans, (c[i] - c[i+1])*(c[i] - c[i+1]) +
                dp (i + 2, k - 1));
    return mdp[i][k] = ans;
}

int main() {
    int t;
    scanf (" %d", &t);
    while (t--) {
        memset (mdp, -1, sizeof(mdp));
        scanf (" %d %d", &K, &n);
        for (int i = 0; i < n; i++)
            scanf (" %d", &c[i]);
        sort (c, c + n, cmp);
        K += 8;
        printf("%d\n", dp(0, K));
    }
}

