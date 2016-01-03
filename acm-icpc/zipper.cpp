#include <bits/stdc++.h>
using namespace std;

int mdp[205][205][3];
int iln, jln;
char w[405], a[205], b[205];

int dp (int i, int j, int pre) {
    if (w[i + j] == 0) return pre;
    int &m = mdp[i][j][pre];
    if (m != -1) return m;
    if (i > iln || j > jln) return 0;
    return m = dp (i+1, j, pre && a[i] == w[i+j]) + dp (i, j+1, pre && b[j] == w[i+j]);
}

int main () {
    int t;
    scanf (" %d", &t);
    for (int tc = 1; tc <= t; tc++) {
        memset (mdp, -1, sizeof mdp);
        scanf (" %s %s %s", a, b, w);
        iln = strlen (a), jln = strlen (b);
        printf ("Data set %d: %s\n", tc, dp (0, 0, true) != 0 ? "yes" : "no");
    }
}
