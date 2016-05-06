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
const int MAX = 1000004;
const int modn = 1000000007;

int id[MAX];

int main() {
    int n, k;
    scanf (" %d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf (" %d", id + i);
    ll l, h;
    l = 0, h = 2*modn;
    while (l != h) {
        ll mid = (l + h)/2;
        ll N = mid*(mid+1)/2;
        if (N >= k) h = mid;
        else l = mid+1;
    }
    printf ("%d\n", id[k-(l-1)*l/2]);
}

