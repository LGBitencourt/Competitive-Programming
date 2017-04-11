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
    long long n;
    scanf("%lld", &n);
    for(long long i=0;i*i<=n;i++) {
        long long k = n-i*i;
        long long p = sqrt(k);
        if (p*p == k || (p+1)*(p+1) == k) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
}

