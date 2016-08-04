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
const int MAXN = 1004;
const int modn = 1000000007;

int a[MAXN];

int main() {
    int n, l;
    scanf (" %d %d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf (" %d", &a[i]);
    sort (a, a + n);
    double d = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] - a[i-1] > 2*d)
            d = ((double) a[i] - a[i-1])/2;
    d = max (d, (double) l - a[n-1]);
    printf ("%.9lf\n", d);
}

