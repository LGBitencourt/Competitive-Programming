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
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXM = 50004;
const int MAXN = 104;
const int modn = 1000000007;

int n, m;
int mdp[MAXN][MAXM];
int c[MAXN];

int dp(int i, int v) {
    if (v == 0) return 0;
    if (i == n) return inf;
    if (mdp[i][v] != -1) return mdp[i][v];
    int ans = dp(i + 1, v);
    if (v - c[i] >= 0)
        ans = min(ans, 1 + dp(i, v - c[i]));
    return mdp[i][v] = ans;
}

int main() {
    while (scanf(" %d %d", &m, &n) && m != 0) {
        for (int i = 0; i < n; i++)
            scanf(" %d", &c[i]);
        memset(mdp, -1, sizeof mdp);
        int ans = dp(0, m);
        if (ans < inf) printf("%d\n", ans);
        else printf("Impossivel\n");
    }
}

