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
int k;
int tam;

void shuffle()
{
    stack<char> s1,s2;
    for ( int i = 0; i < tam; i++ ) {
        if ( ( i % 2 == 0 && tam % 2 == 1 ) || ( i % 2 == 1 && tam % 2 == 0 ) )
            s1.push(s[i]);
        else
            s2.push(s[i]); 
    }
    int x = 0;
    while ( !s2.empty() ) {
        s[x++] = s2.top(); s2.pop();
    }
    while ( !s1.empty() ) {
        s[x++] = s1.top(); s1.pop();
    }
}

int main() {
    scanf(" %s", s);
    tam = strlen(s);
    scanf(" %d", &k);
    for ( int i = 0; i < k; i++ )
        shuffle();
    printf("%s\n", s);
}

