#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 200004;

int n;
char a[MAXN], b[MAXN], c[MAXN], ans[MAXN], f[30];

int main() {
    scanf(" %d", &n);
    scanf(" %s", a);
    scanf(" %s", b);
    scanf(" %s", c);
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i] && b[i] == c[i]) ans[i] = a[i];
        else if (a[i] == b[i] && b[i] != c[i]) ans[i] = a[i];
        else if (b[i] == c[i] && a[i] != b[i]) ans[i] = b[i];
        else if (a[i] == c[i] && b[i] != c[i]) ans[i] = c[i];
        else ans[i] = a[i];
    }
    ans[n] = 0;
    printf("%s\n", ans);
}

