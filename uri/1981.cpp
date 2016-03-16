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
const int inf = 10005;
////////////////0123456789
const int MAX = 10005;
const int modn = 100000007;

char s[inf];
int rep[30];
ll fat[inf];
int l;

void f () {
    fat[0] = 1;
    for (ll i = 1; i <= 10000; i++)
        fat[i] = (i*fat[i-1]) % modn;
}

ll fexp (ll n, ll p) {
    if (p == 0) return 1;
    if (p == 1) return n;
    if (p % 2 == 0) return fexp (n*n % modn, p/2) % modn;
    return (n * fexp (n*n % modn, p/2)) % modn;
}

int main() {
    f();
    while (scanf (" %s", s) && s[0] != '0') {
        l = strlen (s);
        memset (rep, 0, sizeof rep);
        for (int i = 0; i < l; i++)
            rep[s[i] - 'a']++;
        ll inv = 1;
        for (int i = 0; i < 27; i++)
            inv = (inv * fat[rep[i]]) % modn;
        printf ("%lld\n", (fat[l]*fexp(inv, modn-2)) % modn);
    }
}

