#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 1123;
const int modn = 1000000007;

int n;
int a[26];
tuple<ll, int, int> mdp[MAXN];
char s[MAXN];

tuple<ll, int, int> dp(int i) {
    if (i == n) return make_tuple(1, 0, 0);
    if (get<0>(mdp[i]) != -1) return mdp[i];
    ll x;
    int y, z, mn;
    x = 0, y = 0, z = inf;
    mn = a[s[i] - 'a'];
    for (int j = i; j < n; j++) {
        mn = min(mn, a[s[j] - 'a']);
        if (j - i + 1 <= mn) {
            ll u;
            int v, w;
            tie(u, v, w) = dp(j + 1);
            x = (x + u) % modn;
            y = max(y, max(v, j - i + 1));
            z = min(z, w + 1);
        } else break;
    }
    return mdp[i] = make_tuple(x, y, z);
}

int main() {
    memset(mdp, -1, sizeof mdp);
    scanf(" %d", &n);
    scanf(" %s", s);
    for (int i = 0; i < 26; i++)
        scanf(" %d", a + i);
    ll x; 
    int y, z;
    tie(x, y, z) = dp(0);
    printf("%lld\n%d\n%d\n", x, y, z);
}

