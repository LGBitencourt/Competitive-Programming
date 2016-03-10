#include <bits/stdc++.h>
#define pp first
#define jj second
using namespace std;
typedef pair<int, int> pii;
const int MAX = 3005;

pii g[MAX];
pii mdp[MAX][MAX];
int tc, n;

bool cmp (pii a, pii b) {
    if (a.pp != b.pp) return a.pp > b.pp;
    return a.jj < b.jj;
}

pii germito (pii a, pii b) {
    if (a.jj != b.jj) return (a.jj > b.jj) ? a : b;
    return (a.pp > b.pp) ? a : b;
}

pii dp (int i, int q) {
    if (i == n) return pii (0, 0);
    if (mdp[i][q].pp != -1) return mdp[i][q];
    pii a1, a2 = pii (-1, -1), ans;
    a1 = dp (i+1, q+1);
    a1.pp += g[i].pp;
    if (q > 0) {
        a2 = dp (i+1, q-1);
        a2.jj += g[i].jj;
    }
    ans = germito (a1, a2);
    return mdp[i][q] = ans;
}

int main () {
    char name[6];
    scanf (" %d", &tc);
    while (tc--) {
        memset (mdp, -1, sizeof mdp);
        scanf (" %d", &n);
        scanf (" %s", name);
        for (int i = 0; i < n; i++)
            scanf (" %d %d", &g[i].pp, &g[i].jj);
        sort (g, g + n, cmp);
        pii ans;
        if (name[0] == 'P') ans = dp (0, 0);
        else ans = dp (0, 1);
        printf ("%d %d\n", ans.pp, ans.jj);
    }
}
