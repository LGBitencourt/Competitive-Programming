#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 10004;
const int modn = 1000000007;

int main() {
    int t, n;
    scanf (" %d", &t);
    for (int tc = 1; tc <= t; tc++) {
        scanf (" %d", &n);
        if (n == 0) {
            printf ("Case #%d: INSOMNIA\n", tc);
            continue;
        }
        int mask = 0;
        int w = n;
        while (w != 0) {
            mask |= (1 << (w % 10));
            w /= 10;
        }
        w = n;
        while (mask != 1023) {
            w += n;
            int k = w;
            while (k != 0) {
                mask |= (1 << (k % 10));
                k /= 10;
            }
        }
        printf("Case #%d: %d\n", tc, w);
    }
}
