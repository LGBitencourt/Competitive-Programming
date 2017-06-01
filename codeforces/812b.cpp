#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 20;

int n, m, w;
int d[MAXN][2];
char g[15][150];

int f(int h, int l) {
    if (h == n) return d[h][l];
    return min(2 * d[h][l] + f(h + 1, l), m + 1 + f(h + 1, (l + 1) & 1)) + 1;
}

int main() {
    scanf(" %d %d", &n, &m);
    for (int i = n - 1; i >= 0; i--)
        scanf(" %s", g[i]);
    for (int i = 0; i < n; i++) {
        int li = 0, ri = m + 1;
        for (int j = 1; j < m + 2; j++)
            if (g[i][j] == '1') {
                li = max(li, j), ri = min(ri, j);
                w = min(i, n - 1);
            }
        d[i][0] = li, d[i][1] = m - ri + 1;
    }
    n = w;
    printf("%d\n", f(0, 0));
}

