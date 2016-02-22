#include <bits/stdc++.h>
using namespace std;

int n, p;
int t[35], pizza[35];
int mdp[35][35];

int dp (int i, int p) {
    if (i == n) return 0;
    if (mdp[i][p] != -1) return mdp[i][p];
    int a1 = INT_MIN, a2;
    if (p - pizza[i] >= 0) a1 = t[i] + dp (i+1, p-pizza[i]);
    a2 = dp (i+1, p);
    return mdp[i][p] = max (a1, a2);
}

int main () {
    while (scanf (" %d", &n) && n != 0) {
        memset (mdp, -1, sizeof mdp);
        scanf (" %d", &p);
        for (int i = 0; i < n; i++)
            scanf (" %d %d", &t[i], &pizza[i]);
        printf ("%d min.\n", dp (0, p));
    }
}
