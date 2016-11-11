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

int main() {
    int x, y, t, xi, yi, xj, yj;
    scanf(" %d %d", &x, &y);
    t = abs(x) + abs(y);
    if (x > 0 && y > 0) xi = yj = 0, yi = xj = t;
    else if (x < 0 && y > 0) xi = -t, yi = xj = 0, yj = t;
    else if (x < 0 && y < 0) xi = yj = -t, xj = yi = 0;
    else xi = yj = 0, yi = -t, xj = t;
    printf("%d %d %d %d\n", xi, yi, xj, yj);
}

