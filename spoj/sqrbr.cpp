#include <iostream>
#include <algorithm>

using namespace std;

int ks[40];
int n;

int dp(int s, int j) {
    if (j == 0 || j == n) return 1;
    int ans = 0;
    for (int i = s + 1; i < j + s; i++) {
        if (ks[i] == 1) continue;
        ans += dp(s, i - s + 1) * dp(i + 1, j - i - 1);
    }
    return ans;
}

int main() {
    int t, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < k; i++) {
            int s;
            cin >> s;
            ks[--s] = 1;
        }
        cout << dp(0, 2*n);
    }
}
