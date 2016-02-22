#include <bits/stdc++.h>
using namespace std;

int n, m;
int mdp[2][1000005];
int a[30];

int main () {
    int t;
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d %d", &n, &m);
        for (int i = 0; i < n; i++) scanf (" %d", &a[i]);

        mdp[0][0] = mdp[1][0] = 0;
        for (int i = 1; i <= m; i++) mdp[1][i] = 1000000000;

        for (int i = n-1; i >= 0; i--) {
            for (int j = 1; j <= m; j++)
                mdp[0][j] = min (mdp[1][j], ((j - a[i] >= 0) ? 1 + mdp[0][j - a[i]] : 1000000000));
            for (int j = 1; j <= m; j++)
                mdp[1][j] = mdp[0][j];
        }
        printf ("%d\n", mdp[0][m]);
    }
}

