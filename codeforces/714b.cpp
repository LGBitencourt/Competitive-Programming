#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 1000005;
const int modn = 1000000007;

ll n, sum;
vector<ll> a;

int main() {
    sum = 0;
    scanf (" %lld", &n);
    for (int i = 0; i < n; i++) {
        ll x;
        scanf (" %lld", &x);
        a.pb(x);
    }
    sort(a.begin(), a.end());
    auto it = unique(a.begin(), a.end());
    a.resize(distance(a.begin(), it));
    n = (ll) a.size();

    bool can = true;
    ll target = a[(n - 1)/2];
    int j = 0;
    while (j < n && a[j] == target) j++;
    ll cdd = abs(a[j] - target);
    for (int i = 0; i < n; i++) {
        if (a[i] == target) continue;
        if (a[i] + cdd == target) continue;
        if (a[i] - cdd == target) continue;
        can = false;
    }
    printf("%s\n", can ? "YES" : "NO");
}

