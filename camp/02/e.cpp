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
const int MAXN = 104;
const int modn = 1000000007;

struct s {
    int i, j, d;
    s() {};
    s(int i0, int j0, int d0) {
        i = i0, j = j0, d = d0;
    }
};

int n, m;
int x[4] = {0, 1, 0, -1};
int y[4] = {-1, 0, 1, 0};

int d[MAXN][MAXN][5];
char grid[MAXN][MAXN];

pii ex;

bool can(s p) {
    if (p.i < 0 || p.j < 0 || p.i >= n || p.j >= m) return false;
    if (grid[p.i][p.j] == '*') return false;
    return true;
}

int mod(int a, int b) { return (a % b) + b % b; }

void bfs() {
    while (!q.empty()) {
        s cur = q.front();
        q.pop();
        s nx = s(cur.i + x[cur.d], cur.j + y[cur.d], cur.d);
        if (can(nw)) {
            if (d[nx.i][nx.j][nx.d] == INT_MAX)
                d[nx.i][nx.j][nx.d] = d[cur.i][cur.j][cur.d] + 1,
                    q.push(nx);
        }
        if (d[nx.i][nx.j][mod(nx.d + 1, 4)] == INT_MAX)
            d[nx.i][nx.j][mod(nx.d + 1, 4)] = d[nx.i][nx.j][nx.d] + 1,
                q.push(s(nx.i, nx.j, mod(nx.d + 1, 4)));
        if (d[nx.i][nx.j][mod(nx.d - 1, 4)] == INT_MAX)
            d[nx.i][nx.j][mod(nx.d - 1, 4)] = d[nx.i][nx.j][nx.d] + 1,
                q.push(s(nx.i, nx.j, mod(nx.d - 1, 4)));
    }
}

int main() {
    while (scanf (" %d %d", &n, &m), n != 0 && m != 0) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf (" %c", &grid[i][j]);
                if (grid[i][j] == 'X') ex = pii(i, j);
            }
    }
}

