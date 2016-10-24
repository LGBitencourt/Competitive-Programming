#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int inf = 0x3f3f3f3f;
const int MAXN = 505;

int a, h, turn;
int ini[MAXN], rate[MAXN], seen[MAXN], ma[MAXN], mb[MAXN], tw[MAXN][MAXN];
int w[MAXN][MAXN];
vector<int> adj[MAXN];

bool augment(int u, int t) {
    if (seen[u] >= turn) return false;
    seen[u] = turn;
    for (int v : adj[u]) {
        if (tw[u][v] <= t - w[u][v] && (mb[v] == -1 || augment(mb[v], t))) {
            mb[v] = u;
            ma[u] = v;
            return true;
        }
    }
    return false;
}

int max_matching(int t) {
    for (int i = 0; i <= a + h; i++)
        ma[i] = mb[i] = -1;
    int m = 0;
    for (int i = 0; i < h; i++) {
        turn++;
        if (ma[i] == -1 && augment(i, t))
            m++;
    }
    return m;
}

int get_time(int i, int j) {
    /* que homem esse renzo */
    int dtm = rate[i] - rate[j];
    int dti = ini[j] + w[i][j] * rate[j] - ini[i];
    if (dtm <= 0)
        return (dti <= 0) ? 0 : inf;
    if (dti <= 0) return 0;
    return (dti / dtm) + ((dti % dtm) ? 1 : 0);
}

int main() {
    while (scanf(" %d %d", &h, &a) && h != 0) {
        for (int i = 0; i <= a + h; i++)
            adj[i].clear();
        for (int i = 0; i < h; i++)
            scanf(" %d %d", &ini[i], &rate[i]);
        for (int i = h; i < a + h; i++)
            scanf(" %d %d", &ini[i], &rate[i]);
        for (int i = 0; i < h; i++)
            for (int j = h; j < a + h; j++) {
                scanf(" %d", &w[i][j]);
                tw[i][j] = get_time(i, j);
                adj[i].pb(j);
                adj[j].pb(i);
            }
        int l = 0, h = inf, t = -1;
        while (l != h) {
            int m = (l + h) / 2;
            int k = max_matching(m);
            if (k >= a) {
                h = m;
                t = max(t, k);
            } else l = m + 1;
        }
        if (t >= a)
            printf("%d\n", h);
        else printf("IMPOSSIBLE\n");
    }
}

