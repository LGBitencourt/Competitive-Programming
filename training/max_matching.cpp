#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
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

int a, b, tempo;
int ma[MAXN], mb[MAXN], seen[MAXN];
vector<int> adj[MAXN];

bool augment(int u) {
    for (int v : adj[u]) {
        if (seen[v] >= tempo) continue;
        seen[v] = tempo;
        if (mb[v] == -1 || augment(mb[v])) {
            ma[u] = v;
            mb[v] = u;
            return true;
        }
    }
    return false;
}

int max_matching() {
    int m = 0;
    for (int i = 0; i < a; i++) {
        tempo++;
        if (ma[i] == -1 && augment(i)) m++;
    }
    return m;
}

int main() {
    int n;
    scanf(" %d %d %d", &a, &b, &n);
    for (int i = 0; i <= a + b; i++)
        ma[i] = mb[i] = -1;
    while (n--) {
        int u, v;
        scanf(" %d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    printf("%d\n", max_matching());
}

