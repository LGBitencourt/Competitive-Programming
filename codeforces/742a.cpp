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

int fexp(int n, int e) {
    if (e == 0) return 1;
    if (e == 1) return n % 10;
    if (e % 2) return (n * (fexp((n * n) % 10, e/2) % 10)) % 10;
    return (fexp((n * n) % 10, e / 2)) % 10;
}

int main() {
    int e;
    scanf(" %d", &e);
    printf("%d\n", fexp(1378, e));
}

