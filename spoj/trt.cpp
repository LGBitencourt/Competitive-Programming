#include <iostream>
#include <algorithm>

#define MAX 2010

using namespace std;

int n;
int t[5000];
int mdp[MAX][MAX];

int dp (int i, int j) {
    int d = n - j + i;
    if (i == j) return t[i]*d;
    if (mdp[i][j] != 0) return mdp[i][j];
    return mdp[i][j] = max(d * t[i] + dp(i + 1, j), d * t[j] + dp(i, j - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    cout << dp (0, n - 1) << '\n';
}
