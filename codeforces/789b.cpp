#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 10004;

int main() {
    set<ll> bad;
    ll b, q, l, m, ans = 0;
    scanf(" %lld %lld %lld %lld", &b, &q, &l, &m);
    for (int i = 0; i < m; i++) {
        ll x;
        scanf(" %lld", &x);
        bad.insert(x);
    }
    if (q == 1 && bad.find(b) != bad.end()) printf("0\n");
    else if (q == 1) printf("inf\n");
    else if ((!b || !q) && bad.find(0) != bad.end()) printf("0\n");
    else if (!b || !q) printf("inf\n");
    else {
        while (abs(b) <= l) {
            if (bad.find(b) == bad.end()) ans++;
            b *= q;
        }
        printf("%lld\n", ans);
    }
}

