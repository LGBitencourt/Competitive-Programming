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
const int MAXN = 200010;
const int modn = 1000000007;

struct p {
    ll x, y;
    bool type; // true para reta
} point_x[MAXN], point_y[MAXN];

bool cmp_x(p a, p b) {
    return a.x < b.x;
}

int main() {
    int n, m, rx, ry;
    while (scanf (" %d %d", &n, &m), n != 0 && m != 0) {
        ll a, b;
        rx = ry = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %lld %lld", &a, &b);
            point_x[i].x = a, point_x[i].y = b, point_x[i].type = false;
            point_y[i].x = a, point_y[i].y = b, point_y[i].type = false;
        }
        for (int i = 0; i < m; i++) {
            char c;
            ll h;
            scanf (" %c%*c%lld", &c, &h);
            (c == 'x') ? point_x[i+n].x = h, point_x[i+n].y = 0, rx++ : point_y[i+n].x = 0, point_y[i+n].y = h, ry++;
            (c == 'x') ? point_x[i+n].type = true : point_y[i+n].type = true;
        }
        sort(point_x, point_x + rx, cmp_x);
        for (int i = 0; i < n + rx; i++)
            printf("x %lld y %lld type %d\n", point_x[i].x, point_x[i].y, point_x[i].type);
    }
}

