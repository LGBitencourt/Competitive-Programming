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
typedef vector<int> vii;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAX = 100005;
const int modn = 1000000007;

int n, cont;
int ans[MAX], gr[MAX];
vii adj[MAX];
map<vii, int> m;

int dfs (int u) {
    if (gr[u] == 0) {
        ans[u] = 1;
        return 1;
    }
    vii son;
    for (int i = 0; i < adj[u].size (); i++) {
        int v = adj[u][i];
        son.pb (dfs (v));    
    }
    sort (son.begin (), son.end ());
    if (m[son] == 0) m[son] = cont++;
    ans[u] = m[son];
    return ans[u];
}

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int a;
        scanf ("%d", &a);
        adj[a].pb (i+2);
        gr[a]++;
    }
    cont = 2;
    vii son;
    son.pb (1);
    dfs (1);
    for (int i = 1; i <= n; i++) 
        printf ("%d ", ans[i]);
    printf ("\n");
}

