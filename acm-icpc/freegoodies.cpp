#include <bits/stdc++.h>
#define pp first
#define jj second
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1005;

pii g[MAX];
pii mdp[MAX];
int tc, n;

bool cmp (pii a, pii b) {
    if (a.pp != b.pp) return a.pp > b.pp;
    return a.jj < b.jj;
}

pii dp (int i) {
    if (i == n) return pii (0, 0);
    if (mdp[i].pp != -1) return mdp[i];
    pii a1, a2, ans;
    a1 = a2 = dp (i+1);
    a1.jj += g[i].jj, a2.pp += g[i].pp;
    ans = (a1.jj > a2.jj) ? a1 : a2;
    return mdp[i] = ans;
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
        if (name[0] == 'P') {
            pii ans = dp (1);
            ans.pp += g[0].pp;
            printf ("%d %d\n", ans.pp, ans.jj);
            continue;
        }
        pii ans = dp (0);
        printf ("%d %d\n", ans.pp, ans.jj);
    }
}
