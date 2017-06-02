#include <bits/stdc++.h>

#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define inf 100000000000000009LL


using namespace std;

typedef long long ll;
typedef pair <ll, pair <ll, ll>> piii;
typedef pair <ll, ll> pii;

ll n, m, x, M, l, r;
ll we [11234][11234];
ll distTo [11234];
vector <int> adj[11234];
vector <piii> edge;

void clear () {
    for (int i = 0; i <= n; i++)
        adj[i].clear();

}

void dijkstra (ll k) {
    priority_queue<pii> PQ;
    for (int i = 2; i <= n; i++)
        distTo[i] = inf;
    distTo[1] = 0;
    PQ.push (mp (0, 1));
    while (PQ.size() > 0) {
        pii v = PQ.top();
        PQ.pop();
        for (int u : adj[v.ss]) {
            if (distTo[u] > distTo[v.ss] + we[v.ss][u]) {
                distTo[u] = distTo[v.ss] + we[v.ss][u];
                PQ.push (mp (-distTo[u], u));
            }
        }
    }
}


int main () {

    scanf ("%lld %lld %lld", &n, &m, &x);
    for (int i = 0; i < m; i++) {
        ll v, u, t;
        scanf ("%lld %lld %lld", &v, &u, &t);
        adj[u].pb (v);
        adj[v].pb (u);
        we[u][v] = t;
        we[v][u] = t;
        edge.pb (mp (t, mp (v, u)));
    }
    dijkstra ();
    M = distTo[n] + ((distTo[n] * x) / 100.0);
    clear ();
    l = 0;
    r = 1000000000;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        clear ();
        for (int i = 0; i < m; i++) {
            if (edge[i].ff > mid) continue;
            adj[edge[i].ss.ff].pb (edge[i].ss.ss);
            adj[edge[i].ss.ss].pb (edge[i].ss.ff);
        }
        dijkstra ();
        if (distTo[n] <= M) {
            r = mid;
        } else {
            l = mid;
        }
    }
    printf ("%lld\n", r);
    return 0;
}

