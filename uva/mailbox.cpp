#include <bits/stdc++.h>
using namespace std;

int mdp[15][105][105];

int dp (int k, int i, int j) {
    if (i == j) return i;
    if (k == 1) return (j*(j+1)/2) - (i*(i-1)/2);
    if (mdp[k][i][j] != -1) return mdp[k][i][j];
    int ans = INT_MIN;
    for (int l = i; l <= j; l++) {
        int aux = l + max (dp (k-1,
    }
}
