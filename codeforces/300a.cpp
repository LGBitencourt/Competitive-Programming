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
const int MAXN = 104;
const int modn = 1000000007;

int n;
vector<int> lz, gz, z;

int main() {
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf (" %d", &x);
        if (x > 0) gz.pb(x);
        else if (x < 0) lz.pb(x);
    }
    z.pb(0);
    if (lz.size() % 2 == 0) {
        z.pb(lz.back());
        lz.pop_back();
    }
    if (gz.size() == 0) {
        gz.pb(lz.back());
        lz.pop_back();
        gz.pb(lz.back());
        lz.pop_back();
    }
    printf ("%d", (int) lz.size());
    for (int v : lz) printf (" %d", v);
    printf ("\n%d", (int) gz.size());
    for (int v : gz) printf (" %d", v);
    printf ("\n%d", (int) z.size());
    for (int v : z) printf (" %d", v);
    printf ("\n");
}

