#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char str[20];
ll mdp[20][15][2][2];

ll dp (int i, int last, bool x, bool pre) {
    if (str[i] == 0) return x;
    ll &m = mdp[i][last][x][pre];
    if (m != -1) return m;
    m = 0;
    bool f = x;
    for (int d = 0; d <= 9; d++) {
        if (pre && d > str[i] - '0') break;
        bool c = x;
        if (d == 4 || (last == 1 && d == 3)) c = 1;
        m += dp (i + 1, d, c, pre && (str[i] - '0' == d));
    }
    return m;
}

int main () {
    ll n;
    while (scanf (" %lld", &n) != EOF) {
        ll l = 0, h = 1e+19;
        while (l != h) {
            ll mid = l + (h-l)/2;
            memset(mdp, -1, sizeof mdp);
            sprintf (str, "%lld", mid);
            if (mid - dp(0, 0, false, true) >= n) h = mid;
            else l = mid + 1;
        }
        printf ("%lld\n", l);
    }
}
