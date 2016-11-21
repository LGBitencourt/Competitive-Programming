#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
#  define debug(args...) {}
#else
#  define debug(args...) fprintf(stderr, args)
#endif
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int a, d;

int main() {
    int n;
    scanf(" %d", &n);
    while (n--) {
        char c;
        scanf(" %c", &c);
        if (c == 'A') a++;
        else d++;
    }
    if (a == d) printf("Friendship\n");
    else printf("%s\n", a > d ? "Anton" : "Danik");
}

