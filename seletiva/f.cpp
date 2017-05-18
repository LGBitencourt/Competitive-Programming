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
const int MAXN = 1000004;

int prime[MAXN], c[MAXN];

void sieve() {
    for (int i = 2; i < MAXN; i++)
        prime[i] = i;
    for (int i = 2; i < MAXN; i++) {
        if (prime[i] != i) continue;
        for (int j = i + i; j < MAXN; j += i)
            prime[j] = i;
    }
}

int main() {
    int t, n;
    sieve();
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
        int i = n, ans = 0;
        while (i > 1) {
            c[prime[i]]++;
            i /= prime[i];
        }
        i = n;
        while (i > 1) {
            ans = max(ans, c[prime[i]]);
            c[prime[i]] = 0;
            i /= prime[i];
        }
        printf("%d\n", ans);
    }
}

