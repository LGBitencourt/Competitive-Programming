#include <bits/stdc++.h>
using namespace std;

int r, k;
int v[105];
int mdp[105][10005];

int dp (int i, int s) {
    if (s == 0) return 1;
    if (i == r) return 0;
    if (mdp[i][s] != -1) return mdp[i][s];
    int a1 = 0, a2 = 0;
    if (s - v[i] >= 0) a1 = dp (i+1, s - v[i]);
    a2 = dp (i+1, s);
    return mdp[i][s] = max (a1, a2);
}

int main () {
    while (scanf (" %d %d", &r, &k) != EOF) {
        memset (v, 0, sizeof v);
        memset (mdp, -1, sizeof mdp);
        for (int i = 0; i < k; i++) {
            int x, y;
            scanf (" %d %d", &x, &y);
            v[--x]++, v[--y]++;
        }
        printf ("%c\n", dp (0, k) > 0 ? 'S' : 'N');
    }
}
