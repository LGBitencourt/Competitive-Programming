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
const int MAX = 10005;
const int modn = 1000000007;

int mod (int a, int n) {
    if (a >= 0) {
        return a % n;
    }
    return a + n;
}

int main() {
    int n, a, b, s;
    scanf (" %d %d %d", &n, &a, &b);
    a--;
    s = b % n;
    printf ("%d\n", mod (a + s, n)+1);
}

