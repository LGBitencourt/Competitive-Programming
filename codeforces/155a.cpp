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
    int mi, ma, x, n, ans = 0;
    scanf(" %d", &n);
    scanf(" %d", &mi);
    ma = mi;
    for (int i = 1; i < n; i++) {
        scanf(" %d", &x);
        if (x > ma) ans++, ma = x;
        if (x < mi) ans++, mi = x;
    }
    printf("%d\n", ans);
}

