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
const int MAXN = 1104;
const int modn = 100000007;

int n, m;
int a[MAXN], b[MAXN];
int mdp[MAXN][MAXN];

int dp(int i, int x) {
    if (i == n) return !b[x];
    if (mdp[i][x] != -1) return mdp[i][x];
    int ans = (dp(i + 1, x) + dp(i + 1, x ^ a[i])) % modn;
    return mdp[i][x] = ans;
}

int main() {
    int tc;
    scanf(" %d", &tc);
    for (int t = 1; t <= tc; t++) {
        for (int i = 0; i < MAXN; i++) {
            for (int j = 0; j < MAXN; j++)
                mdp[i][j] = -1;
            b[i] = 0;
        }
        scanf(" %d %d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf(" %d", &a[i]);
        for (int i = 0; i < m; i++) {
            int x;
            scanf(" %d", &x);
            b[x] = 1;
        }
        printf("Case %d: %d\n", t, dp(0, 0));
    }
}

