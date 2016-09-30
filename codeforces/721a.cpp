#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define what_is(x) cerr << #x << " is " << x << endl;
#ifdef ONLINE_JUDGE
#  define lld I64d
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

char a[MAXN];
int x[MAXN];

int main() {
    int n;
    int qtd = 0;
    scanf(" %d", &n);
    scanf(" %s", a);
    for (int i = 0; i < n; i++) {
        if (a[i] == 'B') {
            while (i < n && a[i] == 'B')
                x[qtd]++, i++;
            qtd++;
        }
    }
    printf("%d\n", qtd);
    for (int i = 0; i < qtd; i++)
        printf("%d%c", x[i], (i == qtd-1) ? '\n' : ' ');
}

