#include <bits/stdc++.h>
#define MAX 100005
#define Q 1
#define O 0
using namespace std;
typedef long long ll;

struct o {
    ll l, r, d;
} op[MAX];

ll bit[MAX], a[MAX], bit_q[MAX];

ll query (ll x, int t) {
    ll sum = 0;
    if (t == O) {
        for (ll i = x; i > 0; i -= i&-i)
            sum += bit[i];
    } else {
        for (ll i = x; i > 0; i -= i&-i)
            sum += bit_q[i];
    }
    return sum;
}

void update (ll x, ll d, int t) {
    if (t == O) {
        for (ll i = x; i < MAX; i += i&-i)
            bit[i] += d;
    } else {
        for (ll i = x; i < MAX; i += i&-i)
            bit_q[i] += d;
    }
}

int main () {
    ios::sync_with_stdio (false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> op[i].l >> op[i].r >> op[i].d;
    for (int i = 0; i < k; i++) {
        ll x, y;
        cin >> x >> y;
        update (x, 1, Q), update (y + 1, -1, Q);
    }
    for (int i = 1; i <= m; i++) {
        ll val = query (i, Q);
        update (op[i].l, val*op[i].d, O);
        update (op[i].r + 1, -val*op[i].d, O);
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] + query(i, O) << ' ';
    cout << endl;
}
