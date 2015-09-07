#include <iostream>
#include <algorithm>

using namespace std;

int ks[40];
int mdp[40][40];
int n;

int dp(int i, int j) {
    if (j < i) return 0;
    if (i + 1 == j && ks[j] != 1) return 1;
    if (mdp[i][j] != -1) return mdp[i][j];

    int ans = 0;
    for (int k = i + 1; k < j; k++)
        ans += dp(i + 1, k - 1) * dp(k + 1, j);
    return mdp[i][j] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < 40; i++)
            for (int j = 0; j < 40; j++)
                mdp[i][j] = -1;
        for (int i = 0; i < k; i++) {
            int s;
            cin >> s;
            ks[s] = 1;
        }
        cout << dp(1, 2*n) << '\n';
    }
}
