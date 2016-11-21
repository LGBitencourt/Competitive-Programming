#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int main() {
    int n, ma = -1, c = 0;
    scanf(" %d", &n);
    while (n--) {
        int o, i;
        scanf(" %d %d", &o, &i);
        c -= o;
        c += i;
        ma = max(ma, c);
    }
    printf("%d\n", ma);
}

