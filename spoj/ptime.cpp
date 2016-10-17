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

int p[MAXN];
int f[MAXN];

void crivo () {
    for (int i = 2; i < MAXN; i++) {
        if (p[i]) continue;
        for (int j = i; j < MAXN; j += i)
            p[j] = i;
    }
}

int main() {
    int n;
    scanf (" %d", &n);
    crivo();
    int a = n;
    while (n > 1) {
        int k = n;
        while (k > 1) {
            f[p[k]]++;
            k /= p[k];
        }
        n--;
    }
    int qtd = 0;
    for (int i = 2; i <= a; i++)
        if (p[i] == i) {
            if (qtd)
               printf (" * %d^%d", i, f[i]);
            else printf ("%d^%d", i, f[i]);
            qtd++;
        }
    printf ("\n");
}

