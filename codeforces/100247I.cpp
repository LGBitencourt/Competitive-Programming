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
    int n;
    scanf("%d", &n);
    long long s = 0;
    multiset<long long> mt;
    long long aw = 0;
    for(int i=0;i<n;i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        mt.insert(-b);
        s += (long long)b;
        long long t = s - (long long)a - aw;
        while (t > 0) {
            long long k = -*mt.begin();
            aw += k;
            t -= k;
            mt.erase(mt.begin());
        }
    }
    printf("%d\n", n-(int)mt.size());
}

