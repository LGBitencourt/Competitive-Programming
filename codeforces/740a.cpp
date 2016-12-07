#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 10004;

main() {
    int n, a, b, c;
    scanf(" %lld %lld %lld %lld", &n, &a, &b, &c);
    if (n % 4 == 0) puts("0");
    else if (n % 4 == 1) printf("%lld\n", min(3*a, min(c, b + a)));
    else if (n % 4 == 2) printf("%lld\n", min(2*a, min(b, 2*c)));
    else printf("%lld\n", min(a, min(3*c, b + c)));
}
