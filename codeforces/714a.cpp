#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 10005;
const int modn = 1000000007;

int main() {
    ll l1, r1, l2, r2, k, ans = 0;
    scanf (" %lld %lld %lld %lld %lld", &l1, &r1, &l2, &r2, &k);
    ans = min(r1, r2) - max(l1, l2) + 1;
    if (k >= l1 && k <= r1 && k >= l2 && k <= r2) ans--;
    if (ans < 0) printf("0\n");
    else printf("%lld\n", ans);
}
