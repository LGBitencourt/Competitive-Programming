#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define LLD "%I64d"
#  define debug(args...) {}
#else
#  define LLD "%lld"
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 104;
const int modn = 1000000007;

char in[MAXN];
ull mdp_max[MAXN][MAXN], mdp_min[MAXN][MAXN];
ull v[MAXN];
char op[MAXN];

ull dp_max (int i, int j) {
    if (i == j) return v[i];
    if (mdp_max[i][j] != -1) return mdp_max[i][j];
    ull ans = 0;
    for (int k = i; k < j; k++)
        ans = max(ans, 
            (op[k] == '+') ? dp_max (i, k) + dp_max (k+1, j) : 
                             dp_max (i, k) * dp_max (k+1, j));
    return mdp_max[i][j] = ans;
}

ull dp_min (int i, int j) {
    if (i == j) return v[i];
    if (mdp_min[i][j] != -1) return mdp_min[i][j];
    ull ans = inf;
    for (int k = i; k < j; k++)
        ans = min(ans, 
            (op[k] == '+') ? dp_min (i, k) + dp_min (k+1, j) : 
                             dp_min (i, k) * dp_min (k+1, j));
    return mdp_min[i][j] = ans;
}

int main() {
    int t;
    scanf (" %d", &t);
    while (t--) {
        memset (mdp_max, -1, sizeof (mdp_max));
        memset (mdp_min, -1, sizeof (mdp_min));
        int i, j;
        i = j = 0;
        scanf (" %[^\n]", in);
        while (in[i+j] != 0) {
            if (in[i+j] >= '0' && in[i+j] <= '9') {
                v[i] = in[i+j] - '0';
                i++;
            } else {
                op[j] = in[i+j];
                j++;
            }
        }
        printf("%llu %llu\n", dp_max(0, j), dp_min(0, j));
    }
}

