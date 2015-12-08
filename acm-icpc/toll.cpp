#include <bits/stdc++.h>

#define t first
#define v second

using namespace std;

typedef pair<int, int> pii;

priority_queue<pii> q;
vector<pii> adj[60];
int d[60];

int gc (char c) {
    if (isupper (c)) return c - 'A' + 26;
    return c - 'a';
}

int gw (bool u, int w) {
    if (u) return ((w+19)/20);
    return 1;
}

void dijkstra (int o, int s) {
    d[s] = o;
    q.push (pii (o, s));
    while (!q.empty()) {
        int x = q.top().v;
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            int next = adj[x][i].v;
            int w = gw (adj[x][i].t, d[x]);
            if (d[next] < d[x] - w) {
                d[next] = d[x] - w;
                q.push (pii (d[next], next));
            }
        }
    }
}

int main () {
    int tc = 1, n, u, v, p, l, h;
    char a, b;
    while (scanf (" %d", &n), n != -1) {
        for(int i = 0; i < 60; i++) adj[i].clear();
        for (int i = 0; i < n; i++) {
            scanf (" %c %c", &a, &b);
            u = gc (a), v = gc (b);
            adj[u].push_back (pii (v >= 26, v));
            adj[v].push_back (pii (u >= 26, u));
        }
        scanf (" %d %c %c", &p, &a, &b);
        l = 0; h = INT_MAX;
        while (l != h) {
            int mid = l + (h-l)/2;
            for (int i = 0; i < 60; i++)
                d[i] = INT_MIN;
            dijkstra (mid, gc (a));
            if (d[gc (b)] >= p) h = mid;
            else l = mid + 1;
        }
        printf ("Case %d: %d\n", tc++, l);
    }
}
