#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define LLD "%I64d"
#  define debug(args...) {}
#else
#  define LLD "%lld"
#  define debug(args...) fprintf(stderr, args)
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

int initial, n;
int mdp[105][105][280][10];
int a[105];

int dp(int i, int k, int mask, int l) {
    if (i == n) return __builtin_popcount(mask);
    if (mdp[i][k][mask][l] != -1) return mdp[i][k][mask][l];
    int ans = (a[i] != l) + dp(i+1, k, mask & ~(1 << a[i]), a[i]);
    if (k) ans = min(ans, dp(i+1, k-1, mask, l));
    return mdp[i][k][mask][l] = ans;
}

int main() {
    int k, t = 1;
    while (scanf (" %d %d", &n, &k), n != 0) {
        memset (mdp, -1, sizeof mdp);
        initial = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %d", &a[i]);
            a[i] -= 25;
            initial |= (1 << a[i]);
        }
        printf("Case %d: %d\n\n", t++, dp(0, k, initial, -1));
    }
}

