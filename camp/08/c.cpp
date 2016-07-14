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
const int MAXN = 3004;
const int modn = 1000000007;

int v[MAXN];
vector<int> sorted[MAXN];
vector<int> seg[4*MAXN];
map<pii,int> mapp;


int main() {
    int n;
    int maior = 2;
    pii melhor;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        scanf (" %d", &v[i]);
    if (n == 1) {
        printf("1\n%d\n", v[0]);
        return 0;
    }
    if (n == 2) {
        printf("2\n%d %d\n", v[0], v[1]);
        return 0;
    }
    melhor = pii(1,v[0]);
    for (int i = 1; i < n; i++ ) {
        for ( int j = i-1; j >= 0; j-- ) {
            int val = v[i] - v[j];
            int aux = mapp[pii(j,val)];
            if ( aux > 0 ) {
                mapp[pii(i,v[j])] = aux + 1; 
                if ( aux + 1 > maior ) {
                    maior = aux+1;
                    melhor = pii(i,v[j]);
                }
            }
            else {
                mapp[pii(i,v[j])] = 2; 
            }   
        }
    }
    printf("%d\n", maior);
    stack<int> ans;
    ans.push(v[melhor.ff]);
    for ( int i = melhor.first-1; i >= 0; i-- ) {
        if ( v[i] == melhor.second ) {
            ans.push(v[i]);
            melhor = pii(i,v[melhor.first] - melhor.second );
        }
    }
    while (!ans.empty()) {
        printf("%d ", ans.top());
        ans.pop();
    }
    putchar('\n');
}

















