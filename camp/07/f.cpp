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
const int MAXM = 30;
const int modn = 1000000007;

int n, m;
pii s, t;
char grid[MAXN][MAXM];
int dist[MAXN][MAXM];

bool can(pii p) {
    if (p.ff <= 0 || p.ss <= 0 || p.ff > n || p.ss > m) return false;
    return true;
}

pii nx_u(pii x) {
    int i = 1;
    pii nx = pii(x.ff - i, x.ss);
    while (can(nx) && grid[nx.ff][nx.ss] != '#') i++, nx.ff--;
    //if (!can(nx)) return pii(x.ff/2, x.ss);
    return pii(nx.ff + 1 + ((x.ff - nx.ff - 1)/2), x.ss);
}

pii nx_d(pii x) {
    int i = 1;
    pii nx = pii(x.ff + i, x.ss);
    while (can(nx) && grid[nx.ff][nx.ss] != '#') i++, nx.ff++;
    //if (!can(nx)) return pii((n + x.ff)/2, x.ss);
    return pii(nx.ff - 1 - ((nx.ff - x.ff - 1)/2), x.ss);
}

pii nx_r(pii x) {
    int i = 1;
    pii nx = pii(x.ff, x.ss + i);
    while (can(nx) && grid[nx.ff][nx.ss] != '#') i++, nx.ss++;
    //if (!can(nx)) return pii(x.ff, (m + x.ss)/2);
    return pii(x.ff, nx.ss - 1 - ((nx.ss - x.ss - 1)/2));
}

pii nx_l(pii x) {
    int i = 1;
    pii nx = pii(x.ff, x.ss - i);
    while (can(nx) && grid[nx.ff][nx.ss] != '#') i++, nx.ss--;
    //if (!can(nx)) return pii(x.ff, x.ss/2);
    return pii(x.ff, nx.ss + 1 + ((x.ss - nx.ss - 1)/2));
}

/**
 * d == 0 -> up
 * d == 1 -> left
 * d == 2 -> down
 * d == 3 -> right
 */
pii nx_i(pii x, int d) {
    switch (d) {
        case 0:
            return nx_u(x);
            break;
        case 1:
            return nx_l(x);
            break;
        case 2:
            return nx_d(x);
            break;
        case 3:
            return nx_r(x);
            break;
    }
}

void bfs() {
    queue<pii> q;
    q.push(s);
    dist[s.ff][s.ss] = 0;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii nx = nx_i(cur, i);
            if (dist[nx.ff][nx.ss] > dist[cur.ff][cur.ss] + 1 && grid[nx.ff][nx.ss] != '#')
                q.push(nx), dist[nx.ff][nx.ss] = dist[cur.ff][cur.ss] + 1;
        }
    }
}

int main() {
    scanf (" %d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dist[i][j] = inf;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf (" %c", &grid[i][j]);
            if (grid[i][j] == 'S') s = pii(i, j);
            if (grid[i][j] == 'T') t = pii(i, j);
        }
    bfs();
    printf("%d\n", (dist[t.ff][t.ss] != inf) ? dist[t.ff][t.ss] : -1);
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%c ", (dist[i][j] != inf) ? dist[i][j] + '0' : '#');
        putchar('\n');
    }*/
}

