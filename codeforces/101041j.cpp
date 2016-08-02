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
const int MAXN = 20;
const int modn = 1000000007;

int n, M;
pii coins[MAXN];
char grid[55][55];
int dist[MAXN][MAXN];
int mdp[MAXN][(1 << 17)];

int dp (int v, int mask) {
    if (__builtin_popcount(mask) == M) return dist[v][0];
    if (mdp[v][mask] != -1) return mdp[v][mask];
    int ans = inf;
    for (int i = 1; i <= M; i++)
        if (((1 << i) & mask) == 0)
            ans = min (ans, dist[v][i] + dp (i, mask | (1 << i)));
    return mdp[v][mask] = ans;
}

void fill_dist() {
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= M; j++) {
            int dx = abs(coins[i].ff - coins[j].ff);
            int dy = abs(coins[i].ss - coins[j].ss);
            dist[i][j] = 3*min(dx, dy) + 2*(max(dx, dy) - min(dx, dy));
        }
    }
}

int main() {
    while (scanf (" %d", &n), n != 0) {
        M = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                scanf (" %c", &grid[i][j]);
                if (grid[i][j] == 'M') coins[++M] = pii(i, j);
                else if (grid[i][j] == 'D') coins[0] = pii(i, j);
            }
        fill_dist();
        memset (mdp, -1, sizeof(mdp));
        printf("%d\n", dp(0, 0));
    }
}

