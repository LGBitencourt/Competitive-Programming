#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#   define LLD "%I64d"
#else
#   define LLD "%lld"
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

int get_c(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'Z') return 10 + c - 'A';
    if (c >= 'a' && c <= 'z') return 36 + c - 'a';
    if (c == '-') return 62;
    if (c == '_') return 63;
}

int main() {
    char c[MAXN];
    ll ans = 1;
    scanf (" %s", c);
    for (int i = 0; c[i] != 0; i++) {
        int shift = 6 - __builtin_popcount(get_c(c[i]));
        ll cur = 1;
        while (shift--)
            cur *= 3;
        ans *= (ll) cur;
        ans = ans % modn;
    }
    printf(LLD "\n", ans);
}

