#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#  define debug(args...) {}
#else
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 100004;
const int modn = 1000000007;

int x[MAXN];

int main() {
    int n, q;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        scanf (" %d", &x[i]);
    sort (x, x + n);
    scanf (" %d", &q);
    while (q--) {
        int m;
        scanf (" %d", &m);
        printf ("%d\n", upper_bound (x, x + n, m) - x);
    }
}

