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
const int MAXN = 2000005;

int main() {
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long s = 0;
    long long ans = 0;
    map<long long, long long> m;
    m[0] = 1;
    for(int i=0;i<n;i++) {
        long long a;
        scanf("%lld", &a);
        s += a;
        long long p = s-k;
        if (m.find(p) != m.end()) {
            ans += m[p];
        }
        m[s]++;
    }
    printf("%lld\n", ans);
}

