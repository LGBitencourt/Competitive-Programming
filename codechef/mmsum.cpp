#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const ll linf = 0x3f3f3f3f3f3f3f3fll;
/////////////////0123456789
const int MAXN = 100004;
const int modn = 1000000007;

ll v[MAXN], best_l[MAXN], best_r[MAXN];

int main() {
    int t, n;
    scanf (" %d", &t);
    while (t--) {
        ll ans = -linf;
        scanf (" %d", &n);
        for (int i = 1; i <= n; i++) {
            scanf (" %lld", &v[i]);
            best_l[i] = best_r[i] = v[i];
            if (best_l[i-1] > 0) 
                best_l[i] += best_l[i-1];
            ans = max(ans, best_l[i]);
        }
        best_r[n+1] = 0;
        for (int i = n; i > 0; i--)
            if (best_r[i+1] > 0)
                best_r[i] += best_r[i+1];
        for (int i = 1; i <= n; i++)
            if (best_l[i-1] > 0 && best_r[i+1] > 0)
                ans = max (ans, best_l[i-1] + best_r[i+1]);
        printf("%lld\n", ans);
    }
}

