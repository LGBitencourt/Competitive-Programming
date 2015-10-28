#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

#define sd second
#define ff first

using namespace std;

typedef pair<int, int> pii;

int dist[1000], pai[10005];
vector<pii> adj[1000];
vector<pii> jda[1000];
priority_queue<pii> q;
int marked[10005][10005];
int s, d;

void f(int v) {
    for (int i = 0; i < jda[v].size(); i++) {
        if (dist[jda[v][i].sd] + jda[v][i].ff == dist[v]) {
            marked[jda[v][i].sd][v] = 1;
            f(jda[v][i].sd);
        }
    }
}

void dijkstra () {
    dist[s] = 0;
    q.push(pii(0, s));
    pai[s] = -1;
    while (!q.empty()) {
        int x = q.top().sd;
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            pii next = adj[x][i];
            if (marked[x][next.sd]) continue;
            if (dist[next.sd] >= dist[x] + next.ff) {
                dist[next.sd] = dist[x] + next.ff;
                q.push(pii(-dist[next.sd], next.sd));
            }
        }
    }
}

int main () {
    int n, m;
    while (scanf (" %d %d", &n, &m), n != 0) {
        for (int i = 0; i <= n; i++)
            dist[i] = INT_MAX, adj[i].clear(), jda[i].clear();
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++)
                marked[i][j] = 0;
        }

        scanf (" %d %d", &s, &d);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf (" %d %d %d", &u, &v, &w);
            adj[u].push_back(pii(w, v));
            jda[v].push_back(pii(w, u));
        }

        dijkstra();
        if (dist[d] == INT_MAX) {
            printf ("-1\n");
            continue;
        }
        f(d);
        for (int i = 0; i <= n; i++)
            dist[i] = INT_MAX;
        dijkstra();
        printf ("%d\n", dist[d] != INT_MAX ? dist[d] : -1);
    }
}

