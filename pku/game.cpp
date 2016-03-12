#include <bits/stdc++.h>
using namespace std;

const int MAX = 200005;

vector<int> adj[MAX];
bool visited[MAX];
int grid, transf;
int dis[MAX];
int dx[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1},
    dy[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};

bool can (int x, int y) {
    if (x < 0 || y < 0 || x > 3 || y > 3) return false;
    return true;
}

int new_state (int v, int is, int js) {
    printf ("%d\n", v);
    for (int i = 0; i < 9; i++) {
        int x, y, flip;
        x = js + dx[i], y = is + dy[i];
        if (!can (x, y)) continue;
        if (transf & (1 << i)) {
            flip = (1 << (x + 4*y));
            v ^= flip;
        }
    }
    printf ("%d\n", v);
    return v;
}

void bfs () {
    queue<int> q;
    q.push (grid);
    dis[grid] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        visited[v] = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int ns = new_state(v, i, j);
                if (dis[ns] > dis[v] + 1)
                    q.push(ns), dis[ns] = dis[v] + 1;
            }
        }
    }
}

int main () {
    char c, t;
    for (int i = 0; i < MAX; i++)
        dis[i] = INT_MAX;
    for (int i = 0; i < 16; i++) {
        scanf (" %c", &c);
        grid |= (c == 'B') ? (1 << i) : 0;
    }
    for (int i = 0; i < 9; i++) {
        scanf (" %c", &t);
        transf |= (t == '1') ? (1 << i) : 0;
    }
    bfs();
    if (!visited[0] && !visited[(1<<16)-1]) printf ("Impossible\n");
    else printf ("%d\n", min (dis[0], dis[(1 << 16)-1]));
}
