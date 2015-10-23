#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int> > adj[300];
priority_queue<pair<int, int> > q;
int dist[300], pdist[300];
int n, m, c, k;

void dijkstra () {
    while (!q.empty()) {
        pair<int, int> aux = q.top();
        q.pop();
        if (aux.second < c-1) {
            if (pdist[aux.second] + dist[aux.second] < dist[c-1])
                dist[c-1] = pdist[aux.second] + dist[aux.second];
        } else {
            for (int i = 0; i < adj[aux.second].size(); i++) {
                int next = adj[aux.second][i].second;
                if (aux.first + adj[aux.second][i].first < dist[next]) {
                    dist[next] = aux.first + adj[aux.second][i].first;
                    q.push(make_pair(dist[next], next));
                }
            }
        }
    }
}

int main () {
    while (scanf (" %d %d %d %d", &n, &m, &c, &k), n != 0) {
        for (int i = 0; i < n; i++)
            dist[i] = INT_MAX, adj[i].clear();
        for (int i = 0; i < m; i++) {
            int u, v, d;
            scanf (" %d %d %d", &u, &v, &d);
            if (u == v-1 || v == u-1) {
                if (u > v) swap(u, v);
                pdist[u] = d;
            }
            adj[u].push_back(make_pair(d, v));
            adj[v].push_back(make_pair(d, u));
        }
        pdist[c-1] = 0;
        for (int i = c-2; i >= 0; i--) {
            pdist[i] += pdist[i+1];
        }
        q.push(make_pair(0, k));
        dijkstra();
        printf ("%d\n", dist[c-1]);
    }
}

