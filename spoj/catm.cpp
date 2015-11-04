#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int maze[105][105];

struct P {
    int i, j, t;
};

int N, m;
queue<P> q;

int vi[] = {1,0,0,-1};
int vj[] = {0,1,-1,0};

bool valid(int i,int j){
    return (i>0 && j>0 && i<=n && j<=m);
}

bool bfs () {
    while (!q.empty()) {
        P x = q.front();
        q.pop();
        if ((x.i == 0 || x.i == N-1 || x.j == 0 || x.j == m-1) && x.t == 1)
            return true;
    }
    return false;
}

int main () {
    scanf (" %d %d", &N, &m);
    for (int i = 0; i < 3; i++) {
        P n;
        scanf (" %d %d", &n.i, &n.j);
        n.i--, n.j--;
        if (i == 0) n.t = 1;
        else n.t = 2;
        q.push(n);
    }
    printf ("%d\n", bfs());
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < m; j++)
            printf ("%d ", maze[i][j]);
        putchar('\n');
    }
}
