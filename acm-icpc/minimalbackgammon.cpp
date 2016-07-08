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
const int MAXN = 1004;
const int modn = 1000000007;

int n, t, l, b;
bool lose[MAXN], back[MAXN];
double mdp[MAXN][MAXN];

double dp(int i, int k) {
    if (k < 0) return 0;
    if (i == n) return 1;
    if (k == 0) return (i == n) ? 1 : 0;
    if (mdp[i][k] > -eps) return mdp[i][k];
    double p = 0;
    for (int j = 1; j <= 6; j++) {
        int nx = i + j;
        if (nx > n) nx = n - (nx - n);
        if (lose[nx]) p += dp(nx, k-2);
        else if (back[nx]) p += dp(0, k-1);
        else p += dp(nx, k-1);
    }
    return mdp[i][k] = p/6.0;
}

int main() {
    while (scanf (" %d %d %d %d", &n, &t, &l, &b), n != 0 && t != 0) {
        memset (mdp, -1, sizeof mdp);
        for (int i = 0; i <= n; i++)
            lose[i] = back[i] = false;
        for (int i = 0; i < l; i++) {
            int x;
            scanf (" %d", &x);
            lose[x] = true;
        }
        for (int i = 0; i < b; i++) {
            int x;
            scanf (" %d", &x);
            back[x] = true;
        }
        printf("%lf\n", dp(0, t));
    }
}

