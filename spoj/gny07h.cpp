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

ll mdp[MAXN];

ll dp (int n) {
    if (n < 0) return 0;
    if (n == 0 || n == 1) return 1;
    if (n == 2) return 5;
    if (n == 3) return 11;
    if (n == 4) return 36;
    if (mdp[n] != -1) return mdp[n];
    return mdp[n] = dp(n-1) + 5*dp(n-2) + dp(n-3) - dp(n-4);
}

int main() {
    memset(mdp, -1, sizeof (mdp));
    int t, tc = 1;
    scanf (" %d", &t);
    while (t--) {
        int n;
        scanf (" %d", &n);
        printf("%d %lld\n", tc++, dp(n));
    }
}

