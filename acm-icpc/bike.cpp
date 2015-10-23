#include <cstdio>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int mdp[1005][55][15][5];
int n, K;
int Ap[4] = {0, 4, 8, 11};
int S[1005];

int dp(int i, int e, int k, int a) {
    if (k < 0 || e < 0) return 30000;
    if (i == n) return 0;
    if (mdp[i][e][k][a] != -1) return mdp[i][e][k][a];
    int ans = INT_MAX;
    if (k == 0){
        ans = dp(i+1, e, 0, 0) + S[i];
    }
    for (int j = 0; j < 4; j++) {
        if (j != a) k--;
        ans = min(ans, dp(i+1, e-j, k, j) + max(0, S[i] - Ap[j]));
        if (j != a) k++;
    }
    return mdp[i][e][k][a] = ans;
}

int main () {
    int t;
    scanf (" %d", &t);
    for (int z = 1; z <= t; z++) {
        int e;
        scanf (" %d %d %d", &n, &K, &e);
        memset(mdp, -1, sizeof mdp);
        for (int i = 0; i < n; i++)
            scanf (" %d", &S[i]);
        printf ("Case #%d: %d\n", z, dp(0, e, K, 0));
    }
}
