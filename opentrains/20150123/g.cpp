#include <bits/stdc++.h>
#define debug(args...) fprintf (stderr, args)
#define MAX 1005
#define ff first
#define ss second
using namespace std;
typedef pair<int, char> pii;

char maze[MAX][MAX];
int d[MAX][MAX];

struct p {
    int x, y;
};
pii fires[MAX*MAX];
pii jonas;
int f = 0;
queue<p> q;
int l[4] = {0, 0, 1, -1}, c[4] = {1, -1, 0, 0};
int R, C;

bool can (p x) {
    if (x.x >= 0 && x.x < R && x.y >= 0 && x.y < C && maze[x.x][x.y] != '#') return true;
    return false;
}

void bfs () {
    while (!q.empty()) {
        p x = q.front (), n;
        q.pop();
        debug ("%d %d\n", x.x, x.y);
        for (int i = 0; i < 4; i++) {
            n.x = x.x + l[i], n.y = x.y + c[i];
            if (can (n) && d[n.x][n.y] == INT_MAX) {
                d[n.x][n.y] = d[x.x][x.y] + 1;
                q.push (n);
            }
        }
    }
}

int main () {
    scanf (" %d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf (" %c", &maze[i][j]);
            if (maze[i][j] == 'F') fires[f++] = pii (i, j);
            else if (maze[i][j] == 'J') jonas = pii (i, j);
            d[i][j] = INT_MAX;
            if ((i == 0 || i == R-1 || j == 0 || j == C-1) && maze[i][j] == '.') {
                p x;
                x.x = i, x.y = j;
                d[i][j] = 1;
                q.push (x);
            }
        }
    }
    bfs ();
    int mf = INT_MAX;
    for (int i = 0; i < f; i++)
        mf = min (mf, d[fires[i].ff][fires[i].ss]);
    if (d[jonas.ff][jonas.ss] < mf) printf ("%d\n", d[jonas.ff][jonas.ss]);
    else printf ("IMPOSSIBLE\n");
}

