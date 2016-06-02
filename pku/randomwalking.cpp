#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>

#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#   define LLD %I64d
#else
#   define LLD %lld
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

double mdp[1050][105];
vector<int> adj[2005];
int n, e;
double base;

double dp(int u, int k) {
    if (k == 1) return base;
    if (mdp[u][k] > -0.5) return mdp[u][k];
    double ans = 0;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        ans += dp(v, k-1)/adj[v].size();
    }
    return mdp[u][k] = ans;
}

void reset() {
    memset (mdp, -1, sizeof mdp);
    for (int i = 0; i < (1 << (n+1)); i++)
        adj[i].clear();
}

int main () {
    int k;
    while (scanf (" %d %d %d", &k, &n, &e), k != 0 && n != 0 && e != 0) {
        reset();
        bool can = true;
        base = 1.0/(1 << n);
        for (int i = 0; i < e; i++) {
            int x, y;
            scanf (" %d %d", &x, &y);
            adj[x].pb(y), adj[y].pb(x);
        }
        for (int u = 0; u < (1 << n); u++)
            dp (u, k);
        for (int kth = 1; kth <= k; kth++) {
            for (int i = 0; i < n; i++) {
                double prob = 0;
                for (int u = 0; u < (1 << n); u++) {
                    prob += dp(u, kth)*((u >> i) & 1);
                }
                if (prob < 0.25 || prob > 0.75) can = false;
            }
        }
        printf("%s\n", (can) ? "Yes" : "No");
    }
}

