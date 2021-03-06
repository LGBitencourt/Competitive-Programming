#include <bits/stdc++.h>
using namespace std;

int mdp[55][55];
int la, lb;
char a[55], b[55];

int dp (int i, int j) {
    if (i < 0 || j < 0) return 0;
    if (mdp[i][j] != -1) return mdp[i][j];
    if (a[i] == b[j]) return 1 + dp (i-1, j-1);
    dp (i-1, j), dp (i, j-1);
    return mdp[i][j] = 0;
}

int main () {
    while (scanf (" %[^\n]", a) != EOF) {
        scanf (" %[^\n]", b);
        memset (mdp, -1, sizeof mdp);
        la = strlen (a), lb = strlen (b);
        /*int ma = INT_MIN;
        for (int i = 0; i < la; i++) {
            for (int j = 0; j < lb; j++) {
                if (a[i] == b[j]) {
                    if (i == 0 || j == 0) mdp[i][j] = 1;
                    else mdp[i][j] = 1 + mdp[i-1][j-1];
                } else mdp[i][j] = 0;
                ma = max (ma, mdp[i][j]);
            }
        }*/
        int ma = INT_MIN;
        for (int i = 0; i < la; i++)
            for (int j = 0; j < lb; j++)
                ma = max (ma, dp (i, j));
        printf ("%d\n", ma);
    }
}
