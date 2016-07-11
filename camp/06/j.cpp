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

#define int ll
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 1123456;
const int modn = 1000000007;


int H, D, d;
ll size[3];
ll memo[MAXN];

ll dp(int h)
{
    if ( memo[h] != -1 )
        return memo[h];
    double base = d + h*(D-d)/H;
    ll ans = 0ll;
    for(int i = 0ll; i < 3; i++) {
        if ( h - size[i] < 0ll )
           continue;
        double base = d + (h-size[i])*(D-d)/H;
        ll k = (ll)(base/size[i]); 
        ans = max(ans,dp(h-size[i])+ k*k*size[i]*size[i]*size[i]);
    } 
    return memo[h] = ans;
}

main() {
    while(scanf("%lld %lld %lld %lld %lld %lld", &H, &D, &d, &size[0], &size[1], &size[2]) != EOF){
        for ( int i = 0; i < MAXN; i++ )
            memo[i] = -1;
        printf("%lld\n", dp(H));
    }
    return 0;
}

