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
const int MAXN = 204;
const int modn = 1000000007;

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

char grid[MAXN][MAXN];
int d[MAXN][MAXN];

int r, c, blocked, ma;
pii py;
queue<pii> q;
vector<pii> v;

void clr() {
    for (int i = 0; i <= r; i++)
        for (int j = 0; j <= c; j++)
            d[i][j] = inf;
    blocked = 0;
    v.clear();
    ma = INT_MIN;
}

bool can(pii p) {
    if (p.ff < 0 || p.ss < 0 || p.ff >= r || p.ss >= c) return false;
    if (grid[p.ff][p.ss] == 'X') return false;
    return true;
}

void bfs() {
    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            pii nx = pii(cur.ff + x[i], cur.ss + y[i]);
            if (!can(nx)) continue;
            if (d[nx.ff][nx.ss] > d[cur.ff][cur.ss] + 1)
                d[nx.ff][nx.ss] = d[cur.ff][cur.ss] + 1,
                    q.push(nx), ma = max(ma, d[nx.ff][nx.ss]);
        }
    }
}

bool cmp(pii a, pii b) {
    return d[a.ff][a.ss] < d[b.ff][b.ss];
}

int main() {
    while (scanf (" %d %d", &r, &c), r != 0 && c != 0) {
        clr();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf (" %c", &grid[i][j]);
                if (grid[i][j] != 'X') v.pb(pii(i, j));
                else blocked++;
                if (grid[i][j] == 'Y') py = pii(i, j);
                else if (grid[i][j] == 'E') d[i][j] = 0, q.push(pii(i, j));
            }
        }
        bfs();
        sort(v, v + r*c - blocked, cmp);
        // TODO ta foda
    }
}

