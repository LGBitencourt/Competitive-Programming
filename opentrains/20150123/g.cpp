#include <bits/stdc++.h>
#define MAX 1005
using namespace std;
typedef pair<int, int> pii;

int x[5] = {1, -1, 0, 0};
int y[5] = {0, 0, 1, -1};
char A[MAX][MAX];
pii st;
stack<pii> s;
int r, c;

bool pode (int a, int b) {
    if (a >= 0 && a < r && b >= 0 && b < c && A[a][b] != '#') return true;
    return false;
}

int bfs (pii p) {
    queue<pii> q;
    q.push (p);
    while (!q.empty ()) {
        int x, y;
        a = q.front ().ff;
        b = q.front ().ss;
        q.pop ();
        if (A[a][b] == 'F') return 0;
        for (int i = 0; i < 4; i++) {
            if (pode (a+x[i], b+y[i])) {
                q.push (pii (a+x[i], b+y[i]));
            }
        }
    }
    return dis;
}

int main () {
    scanf ("%d %d", &r, &c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf (" %c", &A[i][j]);
            if (A[i][j] == 'J') {
                st.ff = i, st.ss = j;
            }
            if ((i == 0 || i == n-1) && A[i][j] == '.') s.push (pii (i, j));
            else if ((j == 0 || j == n-1) && A[i][k] == '.') s.push (pii (i, j));
        }
    }
    int mi = INT_MAX, res;
    while (!s.empty ()) {
        res = bfs (s.top ());
        if (!res) {
            printf ("IMPOSSIBLE\n");
            return 0;
        }
        mi = min (mi, res);
        s.pop ();
    }
    printf ("%d\n", mi);
}
