#include <cstdio>
#include <queue>
#include <utility>
#include <vector>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

int dist[1000], marked[10005];
vector<int> adj[1000];
struct edge {
    int i, w, p;
    bool operator<(const edge& a) const {
        return i < a.i;
    }
} E[10005];


priority_queue<edge> q;
int s, d, min;

void dijkstra_capetudo () {
    while (!q.empty()) {
        edge aux = q.top();
        q.pop();
        for (int i = 0; i < adj[aux.i].size(); i++) {
            edge next = E[adj[aux.i][i]];
            if (marked[next.i]) continue;
            if (dist[next.i] > dist[aux.i] + next.w) {
                dist[next.i] = dist[aux.i] + next.w;
                q.push(next);
            }
        }
    }
}

int main () {
    int n, m;
    while (scanf (" %d %d", &n, &m), n != 0) {
        for (int i = 0; i <= n; i++)
            dist[i] = INT_MAX;

        scanf (" %d %d", &s, &d);

        for (int i = 0; i < m; i++) {
            int u;
            scanf (" %d %d %d", &u, &E[i].i, &E[i].w);
            adj[u].push_back(i), E[i].p = u;
        }

        dist[s] = 0;
        dijkstra_capetudo();
        printf ("%d\n", dist[d]);
    }
}

