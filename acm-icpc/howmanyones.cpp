#include <cstdio>
#include <cstring>

using namespace std;

typedef long long int lli;

lli mdp[40][40][2];
int n;

lli dp (int i, int sum, bool pre) {
    if (i == -1) return sum;
    if (mdp[i][sum][pre] != -1) return mdp[i][sum][pre];
    lli ans = 0;
    for (int d = 0; d <= 1; d++) {
        if (pre && d > !!(n & (1<<i))) break;
        ans += dp (i - 1, sum + d, pre && (d == !!(n&(1<<i))));
    }
    return mdp[i][sum][pre] = ans;
}

int main () {
    int a, b, t = 1;
    while (scanf (" %d %d", &a, &b), b != 0) {
        lli ma, mi;
        ma = mi = 0;
        memset (mdp, -1, sizeof mdp);
        n = b;
        ma = dp (30, 0, true);
        if (a != 0) {
            memset (mdp, -1, sizeof mdp);
            n = a-1;
            mi = dp (30, 0, true);
        }
        printf ("Case %d: %lld\n", t++, ma-mi);
    }
}
