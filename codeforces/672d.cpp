#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int modn = 1000000007;
const int inf = modn;
/////////////////0123456789
const int MAXN = 500004;

ll t;
int n, k;
int v[MAXN];

int main () {
    scanf (" %d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf (" %d", &v[i]);

    int l = 0, h = 2*inf;
    while (l != h) {
        int  mid = ((ll) l + h)/2;
        if (mid == l) mid++;
        t = 0;
        for (int i = 0; i < n; i++)
            t += max (0, mid - v[i]);
        if (t <= k) l = mid;
        else h = mid - 1;
    }

    t = k;

    for (int i = 0; i < n; i++) {
        t -= max (0, l - v[i]);
        v[i] = max (v[i], l);
    }

    for (int i = 0; i < n; i++)
        if (v[i] == l && t) t--, v[i]++;

    l = 0, h = 2*inf;
    while (l != h) {
        int mid = ((ll) l + h)/2;
        t = 0;
        for (int i = 0; i < n; i++)
            t += max(0, v[i] - mid);
        if (t <= k) h = mid;
        else l = mid + 1;
    }

    t = k;

    for (int i = 0; i < n; i++) {
        t -= max (0, v[i] - l);
        v[i] = min (l, v[i]);
    }

    for (int i = 0; i < n; i++)
        if (v[i] == l && t) v[i]--, t--;

    int ma = -inf, mi = inf;
    for (int i = 0; i < n; i++)
        ma = max(ma, v[i]), mi = min(mi, v[i]);

    printf("%d\n", ma - mi);
}
