#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#  define debug(args...) {}
#else
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

int n, m;
int v[105];
int mdp[105][105];

int dp(int i, int w) {
    if (i == n) return 0;
    if (mdp[i][w] != -1) return mdp[i][w];
    int ans = dp(i + 1, w);
    if (w > 0) ans = max(ans, dp(i + 1, w - 1) - v[i]);
    return mdp[i][w] = ans;
}

int main() {
    scanf(" %d %d", &n, &m);
    memset(mdp, -1, sizeof mdp);
    for (int i = 0; i < n; i++)
        scanf(" %d", v + i);
    printf("%d\n", dp(0, m));
}

