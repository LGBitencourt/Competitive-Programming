#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

ll k;
int a[MAXN], x[MAXN];

bool cmp(int i, int j) {
    return a[i] + ((ll) i) * k < a[j] + ((ll) j) * k;
}

int main() {
    int n;
    ll s;
    scanf(" %d %lld", &n, &s);
    for (int i = 0; i < n; i++) {
        x[i] = i;
        scanf(" %d", a + i);
    }
    ll ans = 0;
    int l = 0, h = n;
    while (l != h) {
        int m = (l + h + 1) / 2;
        ll sum = 0;
        k = m;
        sort(x, x + n, cmp);
        for (int i = 0; i < m; i++) {
            sum += ((ll) a[x[i]]) + ((ll) (x[i] + 1)) * ((ll) m);
        }
        if (sum <= s) {
            l = m;
            ans = sum;
        } else h = m - 1;
    }
    printf("%d %lld\n", l, ans);
}

