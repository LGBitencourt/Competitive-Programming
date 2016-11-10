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
const int MAXN = 10004;

int n;
int v[MAXN];

int main() {
    int mi, x, ma, y;
    mi = inf, ma = -inf;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i]);
    for (int i = 0; i < n; i++) {
        if (v[i] <= mi) x = i, mi = v[i];
        if (v[i] > ma) y = i, ma = v[i];
    }
    printf("%d\n", n + y - x - 1 - (x <= y));
}

