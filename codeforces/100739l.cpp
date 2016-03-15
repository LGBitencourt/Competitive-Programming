#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int modn = 1000000007;

ll fexp (ll b, ll n) {
    if (n == 0) return 1;
    if (n == 1) return b % modn;
    if (n % 2 == 0) return fexp(b*b % modn, n/2);
    return b*fexp(b*b % modn, n/2) % modn;
}

int main () {
    ios::sync_with_stdio(false);
    ll a;
    cin >> a;
    cout << fexp(2, a) << endl;
}
