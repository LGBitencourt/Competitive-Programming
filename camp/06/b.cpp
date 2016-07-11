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

bool mark[10];
int c;

void dig( int x )
{
    int num = x;
    while ( num > 0 ) {
        int d = num % 10;
        if ( !mark[d] ) {
            mark[d] = true;
            c++;
        }
        num /= 10;
    }
}

main() {
    int n;
    while (scanf("%lld", &n) != EOF ) {
       c = 0;
       for ( int i = 0; i <= 9; i++ )
            mark[i] = false;      
       int k;
       for ( k = 1;; k++ ) {
           dig(k*n);
           if ( c >= 10 )
               break;
       }
       printf("%lld\n", k);
    }
    return 0;
}

