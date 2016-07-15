#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#  define debug(args...) {}
#else
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

ll b = 263;
ll bn;

ll mod(ll n) {
    return ((n % modn) + modn) % modn;
}

int getbadness(string p, string t) {
    if (p.length() > t.length()) return 0;
    int badness = 0;
    bn = 1;
    ll hp = 0, ht = 0;
    for (int i = 1; i < p.length(); i++) bn = bn*b % modn;

    for (int i = 0; i < p.length(); i++)
        hp = mod(mod(hp*b) + p[i]);

    for (int i = 0; i < p.length(); i++)
        ht = mod(mod(ht*b) + t[i]);

    if (ht == hp) badness++;

    for (int i = p.length(); i < t.length(); i++) {
        ht = mod(mod(mod(ht - mod(t[i - p.length()] * bn))*b) + t[i]);
        if (ht == hp) badness++;
    }
    return badness;
}

int main() {
    ios::sync_with_stdio(false);
    string p, t, tmp;
    int n;
    while (getline(cin, p), p.compare("EOF") != 0) {
        int ans = -1;
        while (getline(cin, tmp), tmp[0] != 0)
            t += tmp;
        ll badness = getbadness(p, t);
        cin >> n;
        for (int i = 1; i <= n; i++) {
            getline(cin, p);
            while (getline(cin, tmp), tmp[0] != 0)
                t += tmp;
            ll bad = getbadness(p, t);
            if (bad > badness) ans = i, badness = bad;
        }
        cout << ans << endl;
    }
}

