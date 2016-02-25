#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int mdp[1003][1003];

int b, g;

int dp (int i, int j) {
    if (i == 0 || j == 0) return 1;
    if (mdp[i][j] != -1) return mdp[i][j];

}

int main () {
    while (scanf (" %d %d", &b, &g), g != 0) {
        memset (mdp, -1, sizeof mdp);
        printf ("%d\n", dp (b, g));
    }
}
