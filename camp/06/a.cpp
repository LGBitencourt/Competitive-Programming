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

int good[6] = {1,2,3,3,4,10};
int evil[7] = {1,2,2,2,3,5,10};

int ng, ne;

int n;
int tc = 1;

int main() {
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
        ne = 0; ng = 0;
        for ( int k = 0; k < 6; k++ ) {
            int x;
            scanf("%d",&x);
            ng += x*good[k];
        }
        for ( int k = 0; k < 7; k++ ) { 
            int x;
            scanf("%d",&x);
            ne += x*evil[k];
        }
        printf("Battle %d: ", tc++); 
        if ( ng == ne ) 
            printf("No victor on this battle field\n");
        else if ( ng > ne )
            printf("Good triumphs over Evil\n");
        else
            printf("Evil eradicates all trace of Good\n");
    }
    return 0;
}

