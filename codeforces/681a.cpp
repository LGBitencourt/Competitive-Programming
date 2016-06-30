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
const int MAXN = 100004;
const int modn = 1000000007;

int main () {
    int n, b, a;
    bool can = false;
    char name[15];
    scanf (" %d", &n);
    while (n--) {
        scanf (" %s %d %d", name, &a, &b);
        if (a >= 2400 && b > a) can = true;
    }
    printf("%s\n", can ? "YES" : "NO");
}

