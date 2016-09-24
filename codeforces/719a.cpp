#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 104;
const int modn = 1000000007;

int n;
int v[MAXN];

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
        scanf(" %d", &v[i]);
    if (v[n-1] == 0) printf("UP\n");
    else if (v[n-1] == 15) printf("DOWN\n");
    else if (n == 1) printf("-1\n");
    else if (v[n-1] > v[n-2]) printf("UP\n");
    else printf("DOWN\n");
}

