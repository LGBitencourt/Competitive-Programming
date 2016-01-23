#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

bool notf (ll r1, ll r2, ll x1, ll y1, ll x2, ll y2, ll xf, ll yf) {
    ll nr1 = (x1-xf)*(x1-xf)+(y1-yf)*(y1-yf);
    ll nr2 = (x2-xf)*(x2-xf)+(y2-yf)*(y2-yf);
    if (nr1 > r1 && nr2 > r2) return true;
    return false;
}

int main () {
    ll x1, x2, xf, y1, y2, yf, r1, r2;
    int n;
    r1 = r2 = 0;
    scanf (" %d %I64d %I64d %I64d %I64d", &n, &x1, &y1, &x2, &y2);
    for (int i = 0; i < n; i++) {
        scanf (" %I64d %I64d", &xf, &yf);
        if (notf (r1, r2, x1, y1, x2, y2, xf, yf)) {
            ll nr1 = (x1-xf)*(x1-xf)+(y1-yf)*(y1-yf);
            ll nr2 = (x2-xf)*(x2-xf)+(y2-yf)*(y2-yf);
            if (nr1 < nr2) r1 = nr1;
            else r2 = nr2;
        }
    }
    printf ("%I64d\n", r1 + r2);
}
