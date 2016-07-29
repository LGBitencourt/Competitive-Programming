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

ll v[MAXN], p[40];

int main() {
    for (int i = 0; i < 31; i++)
        p[i] = (1LL << i);
    int n;
    ll ans = 0;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        scanf (" %lld", &v[i]);
    sort (v, v + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 31; j++) {
            ll value = p[j] - v[i];
            if (value <= 0) continue;
            auto f = lower_bound(v, v + n, value);
            int qtd = upper_bound(v, v + n, value) - f;
            if (qtd == 0) continue;
            if (*f == v[i]) qtd--;
            ans += qtd;
        }
    }
    printf("%lld\n", ans/2);
}

