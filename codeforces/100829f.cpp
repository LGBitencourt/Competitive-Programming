#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 5123;

int in[4][MAXN];
ll sum[MAXN*MAXN];

int main() {
    int l, s, m, d, b;
    while (scanf(" %d %d %d %d %d", &l, &s, &m, &d, &b), l != 0) {
        for (int i = 0; i < s; i++)
            scanf(" %d", &in[0][i]);
        for (int i = 0; i < m; i++)
            scanf(" %d", &in[1][i]);
        for (int i = 0; i < d; i++)
            scanf(" %d", &in[2][i]);
        for (int i = 0; i < b; i++)
            scanf(" %d", &in[3][i]);

        int sm = 0;
        for (int i = 0; i < d; i++)
            for (int j = 0; j < b; j++)
                sum[sm++] = in[2][i] + in[3][j];
        sort(sum, sum + sm);

        ll ans = 0;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < m; j++) {
                ll t = (ll) in[0][i] + in[1][j];
                if (t > l) continue;
                ans += upper_bound(sum, sum + sm, l - t) - sum;
            }
        }
        printf("%lld\n", ans);
    }
}

