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
const int MAXN = 10004;
const int modn = 1000000007;

int main() {
    int a, b;
    int ans = 0;
    scanf (" %d %d", &a, &b);
    for (int i = a; i <= b; i++) {
        int d = i;
        int k = 0;
        while (d > 0) {
            if (i % d == 0) k++;
            d--;
        }
        if (k % 2) ans++;
    }
    printf("%d\n", ans);   
}

