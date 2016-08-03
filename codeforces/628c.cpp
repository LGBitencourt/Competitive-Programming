#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define LLD "%I64d"
#  define debug(args...) {}
#else
#  define LLD "%lld"
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 100004;
const int modn = 1000000007;

int n, k;
char s[MAXN];

int dist (char a, char b) {
    int x = a - 'a', y = b - 'a';
    return abs (x - y);
}

int get_i(char c) {
    return c - 'a';
}

int main() {
    scanf (" %d %d", &n, &k);
    scanf (" %s", s);
    for (int i = 0; i < n && k > 0; i++) {
        int li = get_i(s[i]);
        if (li + k < 26) {
            s[i] += k;
            k = 0;
        } else if (li - k >= 0) {
            s[i] -= k;
            k = 0;
        } else {
            if (dist('z', s[i]) > dist('a', s[i])) {
                k -= dist('z', s[i]);
                s[i] = 'z';
            } else {
                k -= dist('a', s[i]);
                s[i] = 'a';
            }
        }
    }
    printf("%s\n", (k != 0) ? "-1" : s);
}

