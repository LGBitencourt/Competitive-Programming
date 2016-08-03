#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define LLD "%I64d"
#  define debug(args...) {}
#else
#  define LLD "%lld"
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int main() {
    int t;
    scanf (" %d", &t);
    while (t--) {
        ll k;
        scanf (" %lld", &k);
        k--;
        k = 2LL * k;
        ll l = 0, h = k;
        while (l <= h) {
            ll m = (l + h)/2LL;
            if (m*(m+1) < k) l = m + 1;
            else h = m - 1;
        }
        printf("%d ", (l*(l+1) == k));
    }
    putchar('\n');
}

