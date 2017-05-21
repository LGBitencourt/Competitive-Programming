#include <bits/stdc++.h>

#define ki first
#define li second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;

pii a[MAXN];

bool cmp(pii x, pii y) {
    return min(2 * x.ki, x.li) - min(x.ki, x.li) > min(2 * y.ki, y.li) - min(y.ki, y.li);
}

int main() {
    int n, f;
    scanf(" %d %d", &n, &f);
    for (int i = 0; i < n; i++) {
        int k, l;
        scanf(" %d %d", &k, &l);
        a[i] = pii(k, l);
    }
    sort(a, a + n, cmp);
    ll sum = 0;
    for (int i = 0; i < f; i++)
        sum += (ll) min(2 * a[i].ki, a[i].li);
    for (int i = f; i < n; i++)
        sum += (ll) min(a[i].ki, a[i].li);
    printf("%lld\n", sum);
}

