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

map<int, int> mdp;

int dp(int n) {
    if (n == 1) return 1;
    if (mdp[n] != 0) return mdp[n];
    int ans = (n / 2) + 1;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = min(ans, (((n / i) / 2) + 1) * dp(i));
            if (i > 1)
                ans = min(ans, ((i / 2) + 1) * dp(n / i));
        }
    }
    return mdp[n] = ans;
}

int main() {
    int n;
    scanf(" %d", &n);
    printf("%d\n", dp(n));
}

