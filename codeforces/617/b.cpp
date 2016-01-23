#include <bits/stdc++.h>
using namespace std;

int mdp[105][2][2];
int b[1000];
int n;

int dp (int i, bool h, bool v) {
    printf ("%d %d %d\n", i, h, v);
    if (i == n && v) return 1;
    if (i == n) return 0;
    if (mdp[i][h][v] != -1) return mdp[i][h][v];
    int ans;
    if (b[i] == 1)
        ans = dp (i+1, 0, v) + dp (i+1, 1, v);
    else {
        ans = dp (i+1, h, v);
        if (h) ans += dp (i+1, 0, v);
        else ans += dp (i+1, 0, 0);
    }
    return mdp[i][h][v] = ans;
}

int main () {
    scanf (" %d", &n);
    memset (mdp, -1, sizeof mdp);
    for (int i = 0; i < n; i++)
        scanf (" %d", &b[i]);
    printf ("%d\n", dp (0, 0, 0));
}
