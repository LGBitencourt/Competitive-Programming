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

char s[MAXN];

int main() {
    gets(s);
    int tam = strlen(s);
    bool pode = false;
    for ( int i = 0;!pode; i = (i-1+tam)%tam ) {
        int x = i, y = (x-1+tam) % tam;
        if ( s[x] == s[y] ) {
            x = (x+1)%tam;
            y = (y-1+tam)%tam;
            pode = true;
        }
        while ( x != i ) {
            if ( s[x] != s[y] ) {
                pode = false;
                break;
            }
            x = (x+1)%tam;
            y = (y-1+tam)%tam;
        }
        if ( i == 1 )
           break; 
    }
    if ( pode )
        printf("yes");
    else
        printf("no");
    return 0;
}

