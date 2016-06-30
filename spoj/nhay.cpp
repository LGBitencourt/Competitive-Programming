#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define LLD "%I64d"
#  define debug(args...) {}
#else
#  define LLD "%lld"
#  define debug(args...) fprintf(stderr, args)
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

ll B = 33, Bn, c;
ll hp, hs;
string p, s;

ll mod(ll n) {
    return ((n % modn) + modn) % modn;
}

int main() {
    ios::sync_with_stdio(false);
    ll n;
    while (cin >> n) {
        hp = hs = c = 0;
        Bn = 1;
        cin >> p >> s;
        if (n > s.length()) {
            cout << endl;
            continue;
        }
        for (ll i = 1; i < n; i++)
            Bn = mod(Bn*B);
        for (ll i = 0; i < n; i++)
            hp = mod(mod(hp*B) + p[i]);
        for (ll i = 0; i < n; i++)
            hs = mod(mod(hs*B) + s[i]);
        if (hp == hs) {
            cout << 0 << endl;
            c++;
        }
        for (ll i = n; i < s.size(); i++) {
            hs = mod(mod(mod(hs - mod(s[i - n]*Bn))*B) + s[i]);
            if (hs == hp) {
                c++;
                cout << i - n + 1 << endl;
            }
        }
        if (!c) cout << endl;
    }
}

