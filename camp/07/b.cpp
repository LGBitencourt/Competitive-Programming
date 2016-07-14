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
const int MAXN = 30;
const int modn = 1000000007;

char n[MAXN], aux[MAXN];

int main() {
    scanf (" %s", n);
    int len = strlen(n);
    if (len == 1) {
        printf("%s\n", n);
        printf("0 %s\n", n);
        return 0;
    }
    int start = 1;
    if (n[0] == '1') {
        start = 0;
        len--;
    } else aux[0] = n[0]-1;

    for (int i = start; i < len; i++)
        aux[i] = '9';
    aux[len] = 0;
    ll sum = 0;
    ll b = atoll(aux);
    ll a = atoll(n) - b;
    ll c = a;
    while (c > 0) sum += c % 10, c /= 10;
    c = b;
    while (c > 0) sum += c % 10, c /= 10;
    printf("%lld\n", sum);
    printf("%lld %lld\n", a, b);
}

