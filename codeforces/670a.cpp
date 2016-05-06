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

int main() {
    int n, ma, mi;
    scanf (" %d", &n);
    int day = 0;
    int s = n;
    mi = ma = 0;
    while (s != 0) {
        if (day == 0 || day == 1) ma++;
        s--, day++;
        day = day % 7;
    }
    s = n, day = 0;
    while (s != 0) {
        if (day == 5 || day == 6) mi++;
        s--, day++;
        day = day % 7;
    }
    printf ("%d %d\n", mi, ma);
}
