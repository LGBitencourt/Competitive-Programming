#include <bits/stdc++.h>
#define MAX 505
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

int s[MAX][MAX];
int x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1};
int d[MAX][MAX];
int r, c;
queue<pii> q;

bool is_valid (pii p, int nf) {
    if (p.ff >= 0 && p.ff < r && p.ss >= 0 && p.ss < c && nf > d[p.ff][p.ss]) return true;
    return false;
}

void bfs (int f) {
    d[0][0] = f;
    q.push (pii (0, 0));
    while (!q.empty()) {
        pii p = q.front ();
        q.pop ();
        for (int i = 0; i < 4; i++) {
            pii n = pii (p.ff + x[i], p.ss + y[i]);
            int nf = d[p.ff][p.ss] + s[n.ff][n.ss];
            if (is_valid (n, nf))
                q.push (n), d[n.ff][n.ss] = nf;
        }
    }
}

int main () {
    int t, l, h, m;
    scanf (" %d", &t);
    while (t--) {
        l = h = 1;
        scanf (" %d %d", &r, &c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                scanf (" %d", &s[i][j]);
                if (s[i][j] < 0) h -= s[i][j];
            }
        while (l != h) {
            m = (l + h)/2;
            memset (d, 0, sizeof d);
            bfs (m);
            if (d[r-1][c-1] > 0) h = m;
            else l = m + 1;
        }
        printf ("%d\n", l);
    }
}
