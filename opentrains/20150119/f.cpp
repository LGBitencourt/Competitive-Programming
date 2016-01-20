#include <bits/stdc++.h>

using namespace std;

struct node {
    int t, d, v;
    double id;
};

int n, m, p;
double mdp[205][1005];
vector<node> adj[205];

double dp (int i, int p) {
    if (p == 0 && i == 1) return 0.;
    if (p < 0) return (double) INT_MIN;
    if (mdp[i][p] != 0) return mdp[i][p];
    double tmp = (double) INT_MIN;
    for (int j = 0; j < adj[i].size (); j++) {
        tmp = max (tmp, max (adj[i][j].id + dp (i, p-1),
                    adj[i][j].v + dp (adj[i][j].t, p - adj[i][j].d)));
    }
    return mdp[i][p] = tmp;
}

int main () {
    scanf (" %d %d %d", &n, &m, &p);
    memset (mdp, 0, sizeof mdp);
    for (int i = 0; i < m; i++) {
        int s, t, d, v;
        scanf (" %d %d %d %d", &s, &t, &d, &v);
        node a;
        a.t = t, a.d = d, a.v = v, a.id = (double) (v/d);
        adj[s].push_back (a);
        a.t = s;
        adj[t].push_back (a);
    }
    printf ("%.20f\n", dp (1, p));
}
