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
const int MAXN = 500004;
const int modn = 1000000007;

int n, m, d, l, max_n;
int v[MAXN], bit[MAXN];

void update (int idx, int v) {
    for (int i = idx; i < MAXN; i += i&-i)
        bit[i] += v;
}

int query(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i&-i)
        sum += (bit[i] != 0) ? 1 : 0;
    return sum;
}

int find_l(int x) {
    int l, r;
    l = 1, r = n;
    while (l != r) {
        int mid = l + (r-l)/2;
        if (v[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int find_r(int x) {
    int l, r;
    l = 1, r = n;
    while (l != r) {
        int mid = l + (r-l)/2;
        if (v[mid] > x) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main() {
    scanf (" %d %d %d %d", &n, &m, &d, &l);
    v[1] = 0;
    for (int i = 2; i <= n; i++) {
        scanf (" %d", &v[i]);
        max_n = max(max_n, v[i]);
    }
    for (int i = 0; i < m; i++) {
        int cd;
        scanf (" %d", &cd);
        update(find_l(max(0, cd - l)), 1);
        update(find_r(min(max_n, cd + l)), -1);
    }
    printf("%d\n", query(n));
    for (int i = 0; i < d; i++) {
        int p, r;
        scanf (" %d %d", &p, &r);
        update(find_l(max(0, p - l)), -1);
        update(find_r(min(max_n, p + l)), 1);
        update(find_l(max(0, r - l)), 1);
        update(find_r(min(max_n, r + l)), -1);
        printf("%d\n", query(n));
    }
}

