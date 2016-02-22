#include <bits/stdc++.h>
using namespace std;

int m, v;
int mdp[2][100005];
int mi[1005];

int dp (int i, int v) {
    if (v == 0) return 1;
    if (i == m) return 0;
    if (mdp[i][v] != -1) return mdp[i][v];
    int a1 = 0, a2 = 0;
    if (v-mi[i] >= 0) a1 = dp (i+1, v-mi[i]);
    a2 = dp (i+1, v);
    return mdp[i][v] = max (a1, a2);
}

int main () {
    scanf (" %d %d", &v, &m);
    for (int i = 0; i < m; i++)
        scanf (" %d", &mi[i]);

    mdp[0][0] = mdp[1][0] = 1;
    for (int i = 1; i <= v; i++) mdp[1][i] = 0;

    for (int i = m-1; i >= 0; i--) {
        for (int j = 1; j <= v; j++)
            mdp[0][j] = max (mdp[1][j], ((j - mi[i] >= 0) ? mdp[1][j - mi[i]] : 0));
        for (int j = 1; j <= v; j++)
            mdp[1][j] = mdp[0][j];
    }

    printf ("%c\n", mdp[0][v] > 0 ? 'S' : 'N');
}
