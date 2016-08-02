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
////////////////0123456789
const int MAX = 20;
const int modn = 1000000007;

int n, M;
pii coins[MAXN];
char grid[55][55];
int dist[MAXN][MAXN];
int mdp[MAXN][MAXN];

int dp (int v, int mask) {
    if (__builtin_popcount(mask) == M) return dist[v][0];
    if (mdp[v][mask] != -1) return mdp[v][mask];
    int ans = inf;
    for (int i = 0; i < M; i++)
        if (((1 << i) & mask) == 0)
            ans = min (ans, dist[v][i] + dp (i, masrk | (1 << i)));
    return mdp[v][mask] = ans;
}

void fill_dist() {
    priority_queue<pii> q;
    for (int i = 0; i < M; i++) {
        dist[i][i] = 0;
        q.push(0, i);
        while (!q.empty()) {
            pii c = q.top();
            q.pop();

        }
    }
}

int main() {
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf (" %c", &grid[i][j]);
            if (grid[i][j] == 'M') coins[M++] = pii(i, j);
        }
    fill_dist();
    memset (mdp, -1, mdp);
    printf("%d\n", dp(0, 0));
}

