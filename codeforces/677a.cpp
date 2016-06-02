#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int main() {
    int w = 0, h, n, a;
    scanf (" %d %d", &n, &h);
    for (int i = 0; i < n; i++) {
        scanf (" %d", &a);
        w += (a > h) ? 2 : 1;
    }
    printf("%d\n", w);
}

