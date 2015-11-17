#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

char str[20];
ll mdp[20][15][2][2];

ll dp (int i, int last, int pre, int x) {
    if (str[i] == 0) return x;
    ll &m = mdp[i][last][pre][x];
    if (m != -1) return m;
    m = 0;
    for (int d = 0; d <= 9; d++) {
        if (pre && d > str[i] - '0') break;
        int c = x;
        if (d == 4 || (last == 1 && d == 3)) c = 1;
        m += dp (i + 1, d, pre && str[i] - '0' == d, c);
    }
    return m;
}

int main () {
    ll n;
    while (scanf (" %llu", &n) != EOF) {
        ll l = 0, h = 10000000000000000000;
        while (l != h) {
            ll mid = l + (h-l)/2;
            memset(mdp, -1, sizeof mdp);
            sprintf (str, "%llu", mid);
            if (mid - dp(0, 0, 1, 0) >= n) h = mid;
            else l = mid + 1;
        }
        printf ("%llu\n", l);
    }
}

