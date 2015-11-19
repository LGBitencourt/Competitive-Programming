#include <bits/stdc++.h>

using namespace std;

int t, l, h, w, n, s;

int mdp[105][10005];
char build[105][105][15];
int d[105][105][15];
int ci[6] = {1, -1, 0, 0, 0, 0}, cj[6] = {0, 0, 1, -1, 0, 0}, ck[6] = {0, 0, 0, 0, 1, -1};

struct vol {
    int i, j, k;
};
vol v[100005];


queue<vol> q;

int p[105], S[105];

int dp (int i, int t) {
    if (i == n) return 0;
    if (mdp[i][t] != -1) return mdp[i][t];

    int r1, r2 = INT_MIN;
    if (S[i] <= t)
        r2 = p[i] + dp (i + 1, t - S[i]);
    r1 = dp (i + 1, t);
    return mdp[i][t] = max (r1, r2);
}

bool valid (int i, int j, int k) {
    if ((i >= 0 && i < h) && (j >= 0 && j < w) && (k >= 0 && k < l))
        if (build[i][j][k] != 'X') return true;
    return false;
}

void bfs () {
    while (!q.empty()) {
        vol x = q.front();
        q.pop();
        vol next;

        for (int i = 0; i < 6; i++) {
            next = x;
            next.i += ci[i], next.j += cj[i], next.k += ck[i];
            if (ck[i] == 1 && build[x.i][x.j][x.k] != 'U') continue;
            if (ck[i] == -1 && build[x.i][x.j][x.k] != 'D') continue;
            if (valid (next.i, next.j, next.k)) {
                if (d[next.i][next.j][next.k] > d[x.i][x.j][x.k] + 1)
                    d[next.i][next.j][next.k] = d[x.i][x.j][x.k] + 1, q.push (next);
            }
        }
    }
}

int main () {
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d %d %d %d %d", &l, &h, &w, &n, &s);
        for (int k = 0; k < l; k++)
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++)
                    d[i][j][k] = INT_MAX;
        memset (mdp, -1, sizeof mdp);
        for (int k = 0; k < l; k++)
            for (int i = 0; i < h; i++)
                for (int j = 0; j < w; j++) {
                    scanf (" %c", &build[i][j][k]);
                    if (build[i][j][k] == 'S') {
                        vol s;
                        s.i = i, s.j = j, s.k = k;
                        d[i][j][k] = 0;
                        q.push (s);
                    }
                }
        for (int i = 0; i < n; i++) {
            scanf (" %d %d %d %d", &v[i].k, &v[i].i, &v[i].j, &p[i]);
            v[i].k--, v[i].i--, v[i].j--;
        }
        bfs();
        for (int i = 0; i < n; i++)
            S[i] = 3*d[v[i].i][v[i].j][v[i].k];
        printf ("%d\n", dp(0, s));
    }
}
