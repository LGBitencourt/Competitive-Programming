#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 50004;
const int modn = 1000000007;

char s[MAX];
ull p[MAX];
ull x, y, b = 31;

int hash (int i, int j) {
    if (i >= j) return i == j;
    x = y = 0;
    int ans = 1, l = 0;
    while (i < j) {
        x = x * b + s[i];
        y = p[l] * s[j] + y;
        if (x == y) {
            ans = 2 + hash (i+1, j-1);
            break;
        }
        i++, j--, l++;
    }
    return ans;
}

int main () {
    int t;
    p[0] = 1ULL;
    for (int i = 1; i < MAX; i++)
        p[i] = b*p[i-1];
    scanf (" %d", &t);
    for (int tc = 1; tc <= t; tc++) {
        scanf (" %s", s);
        printf ("Case #%d: %d\n", tc, hash (0, strlen (s) - 1));
    }
}
