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
const int MAXN = 4000004;
const int modn = 1000000007;

int n;
ll v[MAXN];

int main() {
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        scanf (" %lld", &v[i]);
    sort (v, v+n);
    if (n == 1) printf("%lld\n", v[0]);
    else if (v[0] != v[1]) printf("%lld\n", v[0]);
    else if (v[n-1] != v[n-2]) printf("%lld\n", v[n-1]);
    else {
        for (int i = 1; i < n-1; i++)
            if (v[i] != v[i-1] && v[i] != v[i+1]) {
                printf("%lld\n", v[i]);
                break;
            }
    }
}

