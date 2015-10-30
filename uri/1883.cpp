/*
 * @TAG bfs
 * @link https://www.urionlinejudge.com.br/judge/en/problems/view/1883
 */
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>

#define MAX 10005
#define ff first
#define ss second
#define inf 1e9

using namespace std;

typedef pair<int, int> pii;

char maze[MAX][MAX];
int d[MAX][MAX];
pii fires[MAX];
queue<pii> q;
pii s, e;
int n, m, f;

void bfs () {
    d[e.ff][e.ss] = 0;
    q.push(pii(e.ff, e.ss));
    while (!q.empty()) {
        pii x = q.front();
        q.pop();
        if (x.ff > 0) {
            if (d[x.ff-1][x.ss] == inf && maze[x.ff-1][x.ss] != '#') {
                d[x.ff-1][x.ss] = d[x.ff][x.ss] + 1;
                q.push(pii(x.ff-1, x.ss));
            }
        }
        if (x.ff < n) {
            if (d[x.ff+1][x.ss] == inf && maze[x.ff+1][x.ss] != '#') {
                d[x.ff+1][x.ss] = d[x.ff][x.ss] + 1;
                q.push(pii(x.ff+1, x.ss));
            }
        }
        if (x.ss < m) {
            if (d[x.ff][x.ss+1] == inf && maze[x.ff][x.ss+1] != '#') {
                d[x.ff][x.ss+1] = d[x.ff][x.ss] + 1;
                q.push(pii(x.ff, x.ss+1));
            }
        }
        if (x.ss > 0) {
            if (d[x.ff][x.ss-1] == inf && maze[x.ff][x.ss-1] != '#') {
                d[x.ff][x.ss-1] = d[x.ff][x.ss] + 1;
                q.push(pii(x.ff, x.ss-1));
            }
        }
    }
}

int main() {
    int t;
    scanf (" %d", &t);
    while (t--) {
        f = 0;
        scanf (" %d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                d[i][j] = inf, scanf (" %c", &maze[i][j]);
                if (maze[i][j] == 'S')
                    s = pii(i, j);
                else if (maze[i][j] == 'F')
                    fires[f++] = pii(i, j);
                else if (maze[i][j] == 'E')
                    e = pii(i, j);
            }
        }
        bfs();
        int mf = inf;
        for (int i = 0; i < f; i++)
            if (d[fires[i].ff][fires[i].ss] < mf) mf = d[fires[i].ff][fires[i].ss];
        if (d[s.ff][s.ss] < mf)
            printf ("Y\n");
        else printf ("N\n");
    }
}
