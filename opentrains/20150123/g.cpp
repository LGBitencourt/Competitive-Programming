#include <bits/stdc++.h>
#define debug(args...) fprintf (stderr, args)
#define MAX 1005
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

char maze[MAX][MAX];
int d[MAX][MAX];
pii ex[4*MAX], jonas;
queue<pii> q;
int l[4] = {0, 0, 1, -1}, c[4] = {1, -1, 0, 0};
int fex[4*MAX];
int R, C, f, e;

bool can (pii x) {
    if (x.ff >= 0 && x.ff < R && x.ss >= 0 && x.ss < C && maze[x.ff][x.ss] != '#')
        return true;
    return false;
}

void bfs () {
    while (!q.empty()) {
        pii x = q.front (), n;
        q.pop();
        for (int i = 0; i < 4; i++) {
            n.ff = x.ff + l[i], n.ss = x.ss + c[i];
            if (can (n) && d[x.ff][x.ss] + 1 < d[n.ff][n.ss]) {
                d[n.ff][n.ss] = d[x.ff][x.ss] + 1;
                q.push (n);
            }
        }
    }
}

int main () {
    f = e = 0;
    scanf (" %d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf (" %c", &maze[i][j]);
            d[i][j] = INT_MAX;
            if (maze[i][j] == 'F') q.push (pii (i, j)), d[i][j] = 0;
            else if (maze[i][j] == 'J') jonas = pii (i, j);
            if ((i == 0 || i == R-1 || j == 0 || j == C-1)
                    && (maze[i][j] == '.' || maze[i][j] == 'J')) ex[e++] = pii (i, j);
        }
    }
    bfs ();
    for (int i = 0; i < e; i++)
        fex[i] = d[ex[i].ff][ex[i].ss];
    d[jonas.ff][jonas.ss] = 0;
    q.push (jonas);
    bfs ();
    int mi = INT_MAX;
    for (int i = 0; i < e; i++)
        if (d[ex[i].ff][ex[i].ss] < fex[i])
            mi = min (mi, d[ex[i].ff][ex[i].ss]+1);
    if (mi != INT_MAX) printf ("%d\n", mi);
    else printf ("IMPOSSIBLE\n");
}

