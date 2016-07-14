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
const int MAXN = 112;
const int modn = 1000000007;

char grid[MAXN][MAXN];
int mark[MAXN];
int cont[MAXN];
int n;
char s[MAXN];

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %s", grid[i]);   
    }
    memset(mark,-1,sizeof(mark));
    scanf (" %s", s);
    int len = strlen (grid[0]);
    for (int j = 0; j < len; j++) {
        for (int i = 0; i < n; i++) {
            if (grid[i][j] == s[j])
                mark[j] = i, cont[i]++;   
        }
    }
    int maiorInd = 0;
    for (int i = 1; i < n; i++) {
        if (cont[maiorInd] < cont[i])
            maiorInd = i;
    }
    for ( int j = 0; j < len; j++ )
        if ( mark[j] == -1 ) {
            printf("-1\n");
            return 0;
        } 
    printf("%d\n", len - cont[maiorInd]);
    for (int j = 0; j < len; j++) {
        if ( grid[maiorInd][j] != s[j] ) {
            printf("%d %d %d\n", maiorInd+1,mark[j]+1, j+1); 
        }
    }
    return 0;
}

