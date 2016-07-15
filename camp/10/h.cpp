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
typedef vector<int> vi;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 205;
const int modn = 1000000007;

int n, m, u, v, turn;
int seen[MAXN];
pii forbid;
vector<pii> edge;
vi adj[MAXN];

bool dfs (int x) {
    if (x == v) return true;
  //  printf ("x %d\n", x);
    seen[x] = turn;
    bool ans = false;
    for (int i = 0; i < adj[x].size (); i++) {
        int nx = adj[x][i];
        if (forbid.ff == x && forbid.ss == nx) continue;
        if (seen[nx] != turn)
            ans |= dfs (nx);
    }
    return ans;
} 

int main() {
    turn = 1;
    scanf ("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf ("%d %d", &a, &b);
        adj[a].pb (b);
        edge.pb (pii (a, b));
    }
    scanf ("%d %d", &u, &v);
    bool ans = false;
    for (int i = 0; !ans && i < edge.size (); i++) {
        forbid = edge[i];
   //     printf ("i %d\n", i);
        if (!dfs (u)) 
            ans = true;    
        turn++;
    }
    printf ("%d\n", ans);
}

