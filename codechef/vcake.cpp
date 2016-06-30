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
    
ll R, C, a[5];

bool solve(ll r, ll c, int i) {
    if (i == 2) return true;
    if (a[i] % r == 0)
        if (solve(r, c-a[i]/r, i+1)) return true;
    if (a[i] % c == 0)
        if (solve(c, r-a[i]/c, i+1)) return true;
    return false;
}

int main() {
    int t;
    scanf (" %d", &t);
    while (t--) {
        ll r, c;
        scanf (" %lld %lld", &R, &C);
        for (int i = 0; i < 3; i++)
            scanf (" %lld", &a[i]);
        int ans = 0;
        if (a[0]+a[1]+a[2] == R*C) {
            ans += solve(R, C, 0);
            swap(a[0], a[1]);
            ans += solve(R, C, 0);
            swap(a[0], a[2]);
            ans += solve(R, C, 0);
        }
        printf("%s\n", (ans > 0) ? "Yes" : "No");
    }
}

