#include <bits/stdc++.h>
using namespace std;

int mdp[15][105][105];

int dp (int k, int i, int j) {
    if (i == j) return i;
    if (k == 1) return (j*(j+1)/2) - (i*(i-1)/2);
    if (mdp[k][i][j] != -1) return mdp[k][i][j];
    int ans = INT_MAX;
    for (int l = i; l <= j; l++)
        ans = min (ans, max (l+dp (k-1, i, l-1), l+dp (k, l+1, j)));
    return mdp[k][i][j] = ans;
}

int main () {
    int t, k, m;
    scanf (" %d", &t);
    while (t--) {
        memset (mdp, -1, sizeof mdp);
        scanf (" %d %d", &k, &m);
        printf ("%d\n", dp (k, 1, m));
    }
}
