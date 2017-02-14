#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

int n, m;
int f[MAXN], g[MAXN], h[MAXN];

int main() {
    bool ok = true;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++)
        scanf(" %d", f + i);
    for (int i = 1; i <= n; i++) {
        if (f[f[i]] != f[i]) ok = false;
        if (f[i] == i) {
            m++;
            g[i] = m, h[m] = i;
        }
    }
    if (!ok) printf("-1");
    else printf("%d\n", m);
    for (int i = 1; i <= n && ok; i++)
        printf("%d%c", g[f[i]], i == n ? '\n' : ' ');
    for (int i = 1; i <= m && ok; i++)
        printf("%d ", h[i]);
    printf("\n");
}

