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
const int MAXN = 104;

int v[MAXN];

int main() {
    int n, sum = 0;
    bool f = false;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
        sum += v[i];
    }
    sort(v, v + n);
    int c = (100 * v[n-1]);
    if (c >= 45 * sum) f = true;
    else if (c >= 40 * sum) {
        bool can = true;
        for (int i = 0; i < n - 1; i++) {
            int d = v[n-1] - v[i];
            if (100*d < 10 * sum) can = false;
        }
        f = can;
    }
    printf("%d\n", f ? 1 : 2);
}

