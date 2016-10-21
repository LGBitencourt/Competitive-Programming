#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
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
    int k, r, ans = 0;
    scanf(" %d %d", &k, &r);
    int i = k;
    while ((k - r) % 10 != 0 && k % 10 != 0) ans++, k += i;
    ans++;
    printf("%d\n", ans);
}

