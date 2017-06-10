#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef int tA;
typedef null_type tB; // or null_type if you want a set
typedef tree<tA, tB, less<tA>, rb_tree_tag, tree_order_statistics_node_update> ord_set;
// map: tA -> tB com comparador less<tA>
// pode usar como um map normalmente
// s.find_by_order(k) :: retorna iterador para o k-esimo elemento (0-index) (ou s.end())
// s.order_of_key(x)  :: retorna a qtd de elementos estritamente menores que x

typedef long long ll;

const int MAXN = 1000006;
const int inf = 0x3f3f3f3f;

int a[MAXN], b[MAXN], c[MAXN], p[MAXN];
int seg[4*MAXN];

void update(int l, int r, int v, int k, int n) {
    if (l > v || r < v) return;
    if (l == r) {
        seg[n] = k;
        return;
    }
    int m = (l + r) / 2;
    update(l, m, v, k, 2 * n);
    update(m + 1, r, v, k, 2*n + 1);
    seg[n] = min(seg[2*n], seg[2*n + 1]);
}

ll query(int l, int r, int x, int y, int n) {
    if (x > r || y < l) return inf;
    if (l >= x && r <= y) return seg[n];
    int m = (l + r) / 2;
    return min(query(l, m, x, y, 2 * n), query(m + 1, r, x, y, 2 * n + 1));
}

int main() {
    int t, n;
    scanf(" %d", &t);
    while (t--) {
        int ans = 0;
        scanf("%d", &n);
        for (int i = 0; i <= 4*n; i++) {
            seg[i] = inf;
        }
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
            p[i] = i;
        }
        sort(p, p + n, [](int i, int j) { return a[i] < a[j]; });

        for (int i = 0; i < n; i++) {
            if (query(1, n, 1, b[p[i]], 1) > c[p[i]]) ans++;
            update(1, n, b[p[i]], c[p[i]], 1);
        }
        printf("%d\n", ans);
    }
}

