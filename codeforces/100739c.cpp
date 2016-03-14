#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 205;
const int modn = 1000000007;

int n;
char room[MAX][MAX];
int dis[MAX][MAX];
int x[4] = {0, 1, 0, -1},
    y[4] = {1, 0, -1, 0};
int d[4][4] = {
    {0, 1, 2, 3},
    {3, 0, 1, 2},
    {2, 3, 0, 1},
    {1, 2, 3, 0},
};

struct s {
    /*
     * d == direction
     * 0 down; 1 left; 2 up; 3 right
     */
    int i, j, d;
    s() {};
    s(int i0, int j0, int d0) {
        i = i0, j = j0, d = d0;
    };
};

bool valid (int i, int j) {
    if (i < 0 || j < 0 || i >= n || j >= n) return false;
    if (room[i][j] == '#') return false;
    return true;
}

void bfs() {
    int ni, nj, nd;
    queue<s> q;
    dis[0][0] = 0;
    q.push (s(0, 0, 0));
    while (q.size()) {
        s v = q.front();
        if (v.i == n-1 && v.j == n-1 && v.d != 0)
            dis[n-1][n-1] += d[v.d][0];
        q.pop();
        for (int i = 0; i < 4; i++) {
            ni = v.i + y[i], nj = v.j + x[i];
            if (!valid(ni, nj)) continue;
            nd = abs(v.d - d[v.d][i]);
            printf ("%d %d %d\n", nd, dis[ni][nj], dis[v.i][v.j]);
            if (dis[ni][nj] > dis[v.i][v.j]) {
                printf ("%d %d %d %d\n", i, ni, nj, nd);
                q.push(s(ni, nj, i));
                dis[ni][nj] = dis[v.i][v.j] + nd + 1;
            }
        }
    }
}

int main() {
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf(" %c", &room[i][j]);
            dis[i][j] = INT_MAX;
        }
    bfs();
    printf("%d\n", dis[n-1][n-1]);
}

