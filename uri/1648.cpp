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
const int inf = 10000000;
////////////////0123456789
const int MAX = 20;
const int modn = 1000000007;

int p[MAX], a[MAX], n[MAX];
int discount[MAX][MAX];
int m, pizza;

bool minor (pii a, pii b) {
    if ((a.ff/a.ss) < (b.ff/b.ss)) return true;
    return false;
}

double dis (int k) {
    double ans = 1;
    for (int i = 0; i < m; i++) {

    }
}

pii dp (int mask) {
    if (!mask) return pii (0, 0);
    if (mdp[mask].ff != -1) return mdp[mask];
    pii ans = pii (inf, 1);
    // encontrar descontos da pizza i nas pizzas que ja foram pegas
    for (int i = 1; i <= m; i++) {

    }
    return mdp[mask] = ans;
}

int main() {
    while (scanf (" %d", &m) && m > 0) {
        for (int i = 1; i <= m; i++) {
            scanf (" %d %d %d", &p[i], &a[i], &n[i]);
            for (int j = 0; j < n[i]; j++) {
                int x, y;
                scanf (" %d %d", &x, &y);
                discount[i][x] = y;
            }
        }
        pii ans = pii(inf, 1);
        for (int i = 1; i < (1 << m); i++) {
            pizza = i;
            pii d = dp (i);
            if (minor(d, ans)) ans = d;
        }
        printf ("%.4lf\n", ans.ff/ans.ss);
    }
}

