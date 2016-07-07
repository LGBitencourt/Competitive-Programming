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
#define int long long

int n;
int p[8] = {2, 3, 5, 7, 11, 13, 17, 19};
vector<int> fat[300];

bool cmp (int a, int b) {
    return a > b;
}

void solve () {
    fat[1].pb (0);
    for (int i = 2; i <= 150; i++) {
        vector<int> v;
        int x = i;
        for (int j = 2; j <= 150; j++) {
            while (x % j == 0) {
                v.pb (j);
                x /= j;
            }
        }
        sort (v.begin (), v.end (), cmp);
        for (int j = 0; j < v.size (); j++) {
            fat[i].pb (v[j]);
        }
        bool ok = true;
        for (int j = fat[i].size () -1; ok && j >= 0; j--) {
            bool vi = false;
            for (int k = 0; k < j; k++) {
                ll exp = (fat[i][j]) * (fat[i][k]) - fat[i][k];
                if (exp * log (p[k]) < (fat[i][j]-1) * log (p[j])) {
                    fat[i][k] = exp+1;
                    fat[i][j] = 0;
                    vi = true;
                    break;
                }
            }
            if (!vi)
                ok = false;
        }

    }
}

ll fexp (ll a, ll b) {
    if (b == 0ll) 
        return 1ll;
    else if (b == 1ll)
        return a;
    else if (b % 2 == 0ll) 
        return fexp (a*a, b/2);
    return a*fexp (a*a, b/2);
}

main() {
    solve ();
    while (scanf ("%lld", &n) && n != 0) {    
        ll ans = 0;
        for (int i = 0; i < fat[2*n].size (); i++) {
            ans += fexp (p[i], fat[2*n][i]-1);
        }
        ll aux = 0;
        for (int i = 0; i < fat[2*n-1].size (); i++) {
            aux += fexp (p[i], fat[2*n-1][i]-1); 
        }
        ans = min (ans, aux);
        printf ("%lld\n", ans);
    }
}

