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
    int n, m;
    scanf(" %d %d", &n, &m);
    int i = 1;
    while (true) {
        if (m >= i) m -= i;
        else break;
        i++;
        if (i == n + 1) i = 1;
    }
    printf("%d\n", m);
}

