#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 300004;
const int modn = 1000000009;

ll seg[4*MAX], lazy[4*MAX];

void propagate (int l, int r, int n) {
    seg[n] += (r - l + 1) * lazy[n] % modn;
    if (l != r) {
        lazy[2*n] = (lazy[n] + lazy[2*n]) % modn;
        lazy[2*n + 1] = (lazy[n] + lazy[2*n + 1]) % modn;
    }
    lazy[n] = 0;
}

void update (int l, int r, int x, int y, ll v, int n) {
    propagate (l, r, n);
    if (l > y || r < y) return;
    if (l >= x && r <= y) {
        seg[n] += (r - l + 1) * v;
        if (seg[n] >= modn) seg[n] -= modn;
        if (l != r) {
            lazy[2*n] = (lazy[n] + lazy[2*n]) % modn;
            lazy[2*n + 1] = (lazy[n] + lazy[2*n + 1]) % modn;
        }
        return;
    }
    update (l, (l+r)/2, x, y, v, 2*n);
    update (((l+r)/2) + 1, r, x, y, v, 2*n + 1);
    if (l != r) seg[n] = (seg[2*n] + seg[2*n + 1]) % modn;
}

ll query (int l, int r, int x, int y, int n) {
    propagate (l, r, n);
    if (l >= x && r <= y) return seg[n];
    if (l > y || r < x) return 0;
    return query (l, (l+r)/2, x, y, 2*n) + 
        query (((l+r)/2)+1, r, x, y, 2*n + 1);
}

int main() {

}

