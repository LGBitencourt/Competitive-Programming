#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define int ll
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 10004;

int m;
int v[MAXN], freq[MAXN];
pii p[MAXN];

main() {
    int n, ans = 0;
    scanf(" %lld %lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf(" %lld", v + i);
    }
    for (int j = 0; j < m; j++) {
        int x, y;
        scanf(" %lld %lld", &x, &y);
        x--, y--;
        p[j] = pii(x, y);
    }

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = p[i].ff; j <= p[i].ss; j++)
            sum += v[j];
        if (sum < 0) continue;
        for (int j = p[i].ff; j <= p[i].ss; j++)
            freq[j]++;
    }

    for (int i = 0; i < n; i++)
        ans += v[i] * freq[i];

    printf("%lld\n", ans);
}
