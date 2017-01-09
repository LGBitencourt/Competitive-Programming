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
    int n, a, b, d = inf;
    scanf(" %d", &n);
    for (int i = 1; i <= n; i++)
        if (n % i == 0) {
            int ca = n / i;
            if (abs(i - ca) < d) a = ca, b = i, d = abs(i - ca);
        }

    printf("%d %d\n", min(a, b), max(a, b));
}

