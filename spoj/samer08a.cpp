#include <cstdio>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int dist[1000], marked[10005];
vector<int> adj[1000];
struct edge {
    int i, w, p;
} E[10005];
priority_queue<edge> q;

void dijkstra_capetudo (int d) {
    while (!q.empty()) {
        edge aux = q.top();
        if (
        q.pop();
        for (int i = 0; i < adj[edge.i].size(); i++) {
            edge next = adj[edge.i][i];
            if (!marked[next.i]) {

            }
        }
    }
}

int main () {
    int n, m;
    while (scanf (" %d %d", &n, &m), n != 0) {
        scanf (" %d %d", &s, &d);
        for (int i = 0; i < m; i++) {
            int u;
            scanf (" %d %d %d", &u, &E[i].i, &E[i].w);
            adj[u].push_back(i), E[i].p = u;
        }
    }
}

