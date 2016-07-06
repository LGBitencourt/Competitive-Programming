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
const int MAXN = 100004;
const int modn = 1000000007;

struct f {
    ll x, y, z;
    f (){};
    f (ll x0, ll y0, ll z0){
        x = x0, y = y0, z = z0;
    };
} fly[MAXN];

ll norm2(f x) { return abs(x.x) + abs(x.y) + abs(x.z); }

f det(f a, f b) {
    f n;
    n.x = a.y*b.z - a.z*b.y;
    n.y = a.z*b.x - a.x*b.z;
    n.z = a.x*b.y - a.y*b.x;
    return n;
}

ll dot(f a, f b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

int main() {
    int n;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        ll x, y, z;
        scanf (" %lld %lld %lld", &x, &y, &z);
        fly[i] = f(x, y, z);
    }
    if (n <= 3) {
        printf("TAK\n");
        return 0;
    }
    bool line = true;
    f cur;
    f p = f(fly[1].x - fly[0].x, fly[1].y - fly[0].y, fly[1].z - fly[0].z);
    for (int i = 2; i < n; i++) {
        f p_n = f(fly[i].x - fly[0].x, fly[i].y - fly[0].y, fly[i].z - fly[0].z);
        cur = det(p, p_n);
        if (norm2(cur) != 0ll) {
            line = false;
            break;
        }
    }
    if (line) {
        printf("TAK\n");
        return 0;
    }
    bool can = true;
    for (int i = 2; i < n; i++) {
        f p_n = f(fly[i].x - fly[0].x, fly[i].y - fly[0].y, fly[i].z - fly[0].z);
        if (dot(cur, p_n) != 0ll) can = false;
    }
    printf("%s\n", can ? "TAK" : "NIE");
}

