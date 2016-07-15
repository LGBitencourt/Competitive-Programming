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
const int MAXN = 100004;
const int modn = 1000000007;

int n, m;
int price[MAXN], tax[MAXN];
int dp[2][505][2];

int main() {
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < n; i++) 
        scanf ("%d", &price[i]);
    for (int i = 1; i < n; i++) 
        scanf ("%d", &tax[i]);
    for (int j = 0; j <= m; j++) 
        dp[1][j][true] = dp[1][j][false] = 0;
    bool x = 1, nx;
    for (int i = n-1; i >= 0; i--) {
        nx = x;
        x = !x;
        dp[nx][0][true] = dp[nx][0][false] = 0;
        for (int k = 1; k <= m; k++) {
            dp[x][k][true] = max (price[i] + tax[i] + dp[nx][k-1][false], 
                                  max (tax[i] + dp[nx][k-1][true], dp[nx][k][true]));
            dp[x][k][false] = max (-price[i] + dp[nx][k][true], dp[nx][k][false]);
        }
    }
    printf ("%d\n", dp[x][m][false]);
}

