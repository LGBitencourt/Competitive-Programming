#include <bits/stdc++.h>
using namespace std;

int N, nop;
int mdp[35][35][7000];
int nb[35], op[35], r[7000];

int dp (int i, int p, int c) {
    if (mdp[i][p][c + 3500] != -1) return mdp[i][p][c + 3500];
    if (i == N) return r[c + 3500] = 1;
    int eval = c + nb[i]*op[i]*((p % 2) ? -1 : 1);
    int ans = dp (i + 1, p, eval);
    if (op[i] == -1) ans += dp (i + 1, p + 1, eval);
    if (p > 0) ans += dp (i + 1, p - 1, eval);
    return mdp[i][p][c + 3500] = ans;
}

int main () {
    char str[500];
    char *pch;
    while (scanf (" %[^\n]", str) != EOF) {
        nop = op[0] = 1, N = 0;
        pch = strtok (str, " ");
        while (pch != NULL) {
            if (pch[0] == '+') op[nop++] = 1;
            else if (pch[0] == '-') op[nop++] = -1;
            else nb[N++] = atoi (pch);
            pch = strtok (NULL, " ");
        }
        for (int i = 0; i < 35; i++)
            for (int j = 0; j < 35; j++)
                for (int k = 0; k < 7000; k++)
                    mdp[i][j][k] = -1, r[k] = 0;
        int ans = 0;
        dp (0, 0, 0);
        for (int i = 0; i < 7000; i++) ans += r[i];
        printf ("%d\n", ans);
    }
}
