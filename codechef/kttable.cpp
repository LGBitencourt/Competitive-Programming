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
const int MAX = 10004;
const int modn = 1000000007;

int a[MAX];

int main() {
    int t, n;
    scanf (" %d", &t);
    while (t--) {
        int ans = 0;
        scanf (" %d", &n);
        for (int i = 0; i < n; i++)
            scanf (" %d", &a[i]);
        int b, ant = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %d", &b);
            if (a[i]-ant >= b) ans++;
            ant = a[i];
        }
        printf("%d\n", ans);
    }
}

