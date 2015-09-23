#include <iostream>

using namespace std;

int v[10005];
int n, u, q;

int query(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= i&-i)
        sum += v[i];
    return sum;
}

void update(int idx, int x) {
    for (int i = idx; i <= n; i += i&-i)
        v[i] += x;
}

int main () {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> u;
        for (int i = 0; i <= n; i++) v[i] = 0;
        for (int i = 0; i < u; i++) {
            int l, r, val;
            cin >> l >> r >> val;
            l++, r++;
            update(l, val);
            update(r + 1, -val);
        }
        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            cout << query(x + 1) << '\n';
        }
    }
}
