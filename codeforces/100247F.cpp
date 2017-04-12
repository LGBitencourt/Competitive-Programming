#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 200004;

int n, p, q;
int a[MAXN];

bool can(int k) {
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        if (a[i] - k*q > 0) pq.push(a[i] - k*q);
    if (p == q && pq.size()) return false;
    int w = p - q;
    while (k > 0 && pq.size()) {
        int x = pq.top();
        pq.pop();
        int b = (x + w - 1) / w;
        k -= b;
        if (k < 0) return false;
    }
    if (pq.size()) return false;
    return true;
}

main() {
    scanf(" %lld %lld %lld", &n, &p, &q);
    for (int i = 0; i < n; i++)
        scanf(" %lld", a + i);

    int l = 1, h = 1000000000;
    while (l != h) {
        int m = (l + h) / 2;
        if (can(m)) h = m;
        else l = m + 1;
    }
    printf("%lld\n", l);
}

