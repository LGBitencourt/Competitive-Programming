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
int dis[MAX][MAX][MAX];
int x[4] = {0, 1, 0, -1},
    y[4] = {1, 0, -1, 0};

struct s {
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
    dis[0][0][0] = 0;
    q.push (s(0, 0, 0));
    while (q.size()) {
        int ni, nj;
        s v = q.front();
        q.pop();
        ni = v.i + y[v.d], nj = v.j + x[v.d];
        if (valid(ni, nj)) {
            if (dis[ni][nj][v.d] == INT_MAX)
                dis[ni][nj][v.d] = dis[v.i][v.j][v.d] + 1,
                    q.push(s(ni, nj, v.d));
        }
        if (dis[v.i][v.j][(v.d+1)%4] == INT_MAX)
            dis[v.i][v.j][(v.d+1)%4] = dis[v.i][v.j][v.d]+1,
                q.push(s(v.i, v.j, (v.d+1)%4));
    }
}

int main() {
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            scanf(" %c", &room[i][j]);
            for (int k = 0; k < 4; k++)
                dis[i][j][k] = INT_MAX;
        }
    bfs();
    printf("%d\n", dis[n-1][n-1][0]);
}

