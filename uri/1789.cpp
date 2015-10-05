#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

int mpd[2005][5000];
int c[5005], v[5005];
int n;

int dp(int i, int l) {
    if (i == n || l < 0) return 0;
    if (mpd[i][l] != -1) return mpd[i][l];
    int r1, r2, r3;
    r1 = r2 = INT_MIN;
    if (l - c[i] >= 0)
        r1 = v[i] + dp(i, l - c[i]),
           r2 = v[i] + dp(i + 1, l - c[i]);
    r3 = dp(i + 1, l);
    return mpd[i][l] = max(r1, max(r2, r3));
}

int main () {
    int t;
    cin >> n >> t;
    memset(mpd, -1, sizeof mpd);
    for (int i = 0; i < n; i++)
        cin >> c[i] >> v[i];
    cout << dp(0, t) << endl;
}
