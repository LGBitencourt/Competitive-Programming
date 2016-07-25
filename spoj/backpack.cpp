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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 104;
const int MAXV = 32004;
const int modn = 1000000007;

int n, v_max;
vector<int> m;
vector<int> attach[MAXN];

int c[MAXN], v[MAXN];
int mdp[MAXN][MAXV];

int dp(int i, int k) {
    if (k < 0) return INT_MIN;
    if (i == (int) m.size()) return 0;
    if (mdp[i][k] != -1) return mdp[i][k];
    int ans = dp(i + 1, k);
    int cur_v = k - v[m[i]];
    if (cur_v >= 0) {
        ans = max(c[m[i]] + dp(i + 1, cur_v), ans);
        for (auto x : attach[m[i]]) {
            if (cur_v - v[x] < 0) continue;
            ans = max(c[m[i]] + c[x] + dp(i + 1, cur_v - v[x]), ans);
        }
        if (attach[m[i]].size() >= 2) {
            int sum_c = 0, sum_v = 0;
            for (int j = 0; j < 2; j++)
                sum_c += c[attach[m[i]][j]], sum_v += v[attach[m[i]][j]];
            if (cur_v - sum_v >= 0)
                ans = max(ans, sum_c + c[m[i]] + dp(i + 1, cur_v - sum_v));
            if (attach[m[i]].size() == 3) {
                sum_c += c[attach[m[i]][2]];
                sum_v += v[attach[m[i]][2]];
                if (cur_v - sum_v >= 0)
                    ans = max(c[m[i]] + sum_c + dp(i + 1, cur_v - sum_v), ans);
                sum_c = sum_c - c[attach[m[i]][0]];
                sum_v = sum_v - v[attach[m[i]][0]];
                if (cur_v - sum_v >= 0)
                    ans = max(ans, c[m[i]] + sum_v + dp(i + 1, cur_v - sum_v));
            }
        }
    }
    return mdp[i][k] = ans;
}

int main() {
    int t;
    scanf (" %d", &t);
    while (t--) {
        memset (mdp, -1, sizeof (mdp));
        m.clear();
        scanf (" %d %d", &v_max, &n);
        for (int i = 0; i <= n; i++)
            attach[i].clear();
        for (int i = 0; i < n; i++) {
            int ci, u;
            scanf (" %d %d %d", &v[i], &ci, &u);
            c[i] = ci * v[i];
            if (u == 0) m.pb(i);
            else attach[u-1].pb(i);
        }
        printf("%d\n", dp(0, v_max));
    }
}

