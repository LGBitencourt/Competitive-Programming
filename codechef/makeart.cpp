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
const int MAXN = 100004;
const int modn = 1000000007;

int c[MAXN];

int main() {
    int t, n;
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d", &n);
        for (int i = 0; i < n; i++)
            scanf (" %d", &c[i]);
        bool can = false;
        for (int i = 2; i < n; i++)
            if (c[i] == c[i-1] && c[i-1] == c[i-2]) can = true;
        printf ("%s\n", (can) ? "Yes" : "No");
    }
}

