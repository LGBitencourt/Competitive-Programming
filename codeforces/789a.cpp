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
    int n, k, bags = 0;
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x;
        scanf(" %d", &x);
        bags += (x + k - 1) / k;
    }
    printf("%d\n", (bags + 1) / 2);
}

