#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int mdp[1005][55][15];
int n, K;
int Ap[5] = {0, 4, 8, 11};
int S[1005];

int dp(int i, int e, int c) {
    if (c >= K || e < 0) return 30000;
    if (i == n) return 0;
    int ans = INT_MAX;
    for (int j = 0; j < 4; j++) {
        ans = min(ans, dp(i+1, e-j, c+1) + S[i]);
    }
    return mdp[i][e][c] = ans;
}

int main () {
    int t;
    scanf (" %d", &t);
    for (int z = 1; z <= t; z++) {
        int e;
        scanf (" %d %d %d", &n, &K, &e);
        for (int i = 0; i < n; i++)
            scanf (" %d", &S[i]);
        printf ("Case #%d: %d\n", z, dp(0, e, 0));
    }
}
