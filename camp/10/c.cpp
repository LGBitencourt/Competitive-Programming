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
#define int ll
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int fexp (int x, int y) {
    if (y == 0ll) return 1ll;
    if (y == 1ll) return x;
    if (y % 2ll == 0ll) return fexp ((x*x) % modn, y/2ll);
    return (x * fexp ((x*x) % modn, y/2ll)) % modn;
}

int inv (int x) { return fexp (x, modn-2ll); }

int fat (int x) {
    int ans = 1;
    while (x > 0) {
        ans = (ans*x) % modn;
        x--;
    }
    return ans;
}

main () {
    int n, m;
    scanf ("%lld %lld", &n, &m);
    int num = fat (n+m);
    int deno = (fat (n) * fat (m)) % modn;
    num = (num * inv (deno)) % modn;
    printf ("%lld\n", num);
}

