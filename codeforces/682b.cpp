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
const int MAXN = 1000004;
const int modn = 1000000007;

int a[MAXN];

int main() {
    int n, k = 0;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        scanf (" %d", &a[i]);
    sort(a, a+n);
    for (int i = 0; i < n; i++)
        if (a[i] > k) k++;
    printf("%d\n", ++k);
}

