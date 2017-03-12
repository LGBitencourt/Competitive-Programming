#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 21234;

int v[MAXN];

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int n, k;
        scanf(" %d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf(" %d", v + i);
        sort(v, v + n);
        int ans = v[k - 1] - v[0];
        for (int i = k; i < n; i++)
            ans = min(ans, v[i] - v[i - k + 1]);
        printf("%d\n", ans);
    }
}

