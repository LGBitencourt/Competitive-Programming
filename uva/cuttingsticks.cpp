#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int n, t;
int cuts[55];
int mdp[1005][1005];

int dp(int i, int j) {
    if (j - i == 1) return 0;
    if (mdp[i][j] != -1) return mdp[i][j];
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
        ans = min(ans, dp(i, k) + dp(k, j) + cuts[j] - cuts[i]);
    mdp[i][j] = ans;
    return ans;
}

int main() {
    while (cin >> t, t != 0) {
        memset(mdp, -1, sizeof(mdp));
        cin >> n;
        cuts[0] = 0, cuts[n + 1] = t;
        for (int i = 1; i <= n; i++)
            cin >> cuts[i];
        cout << "The minimum cutting is " << dp(0, n + 1) << ".\n";
    }
}
