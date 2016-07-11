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
const int MAX = 105;
const int modn = 1000000007;

int k;
int aux[MAX], bin[MAX];
ll n;
ll me[MAX][MAX][3];

ll dp (int dig, int qtdOne, bool pre) {
    if (dig == k) {
        //printf ("qtdOne %d\n", qtdOne);
        return qtdOne % 3 == 0 ? 1 : 0;
    }
    if (me[dig][qtdOne][pre] != -1) return me[dig][qtdOne][pre];
    ll ans = 0;
    for (int i = 0; i <= 1; i++) {
        //printf ("antes char %d\n", bin[dig]);
        if (pre && i > bin[dig]) break;
        //printf ("depois\n");
        ans += dp (dig+1, qtdOne + (i == 1 ? 1 : 0), pre && (i == bin[dig]));
    }
    return me[dig][qtdOne][pre] = ans;
}

int main() {
    while (scanf ("%lld", &n) != EOF) {
        ll a = n;
        k = 0;
        memset (me, -1, sizeof me);
        while (n > 0) {
            aux[k++] = n%2;
            n /= 2;
        }

        for (int i = k-1; i >= 0; i--) 
            bin[k-1-i] = aux[i];
        /*for (int i = 0; i < k; i++)
            printf ("%d", bin[i]);
        printf ("\n");*/
        ll ans = dp (0, 0, 1)-1;
        printf ("Day %lld: Level = %lld\n", a, ans);
    }
}

