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

int v[MAXN];

int main() {
    int n;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        scanf (" %d", &v[i]);
    int c = 1, ans = 1;
    for (int i = 1; i < n; i++) {
        if (v[i-1] < v[i]) c++;
        else c = 1;
        ans = max (ans, c);
    }
    printf("%d\n", ans);
}

