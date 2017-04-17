#include <bits/stdc++.h>

#define wg first
#define vx second
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int, int, int> tiii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 1123;
const int MAXS = 123;

int n, m, s, t, c, d;
vector<pii> adj[MAXN];
int mp[MAXN], price[MAXN], cost[MAXS][1123456], ds[MAXN], station[MAXN];
int dist[MAXS][MAXS];

void dijkstra(int u) {
    priority_queue<pii> pq;
    pq.push(pii(0, u));
    for (int i = 0; i <= n; i++)
        ds[i] = inf;
    ds[u] = 0;
    while (pq.size()) {
        pii x = pq.top();
        pq.pop();
        for (pii v : adj[x.vx])
            if (ds[v.vx] > ds[x.vx] + v.wg && ds[x.vx] + v.wg <= t) {
                ds[v.vx] = ds[x.vx] + v.wg;
                pq.push(pii(-ds[v.vx], v.vx));
            }
    }
    for (int i = 1; i <= n; i++)
        if (station[i])
            dist[mp[u]][mp[i]] = dist[mp[i]][mp[u]] = ds[i];
}

void djalma(int u) {
    priority_queue<tiii> pq;
    pq.push(tiii(0, 0, u));
    for (int i = 0; i <= s; i++)
        for (int j = 0; j < 1000006; j++)
            cost[i][j] = inf;
    cost[u][0] = 0;
    while (pq.size()) {
        int vx, cst, gas;
        tie(cst, gas, vx) = pq.top();
        cst *= -1;
        pq.pop();
        for (int i = 1; i <= s; i++) {
            if (i == vx) continue;
            int buy;
            if (price[vx] > price[i]) {
                if (gas > dist[vx][i]) continue;
                buy = dist[vx][i] - gas;
            } else {
                buy = t - gas;
            }
            if (dist[vx][i] > t) continue;
            if (cost[i][gas + buy - dist[vx][i]] > cost[vx][gas] + buy * price[vx]) {
                cost[i][gas + buy - dist[vx][i]] = cost[vx][gas] + buy * price[vx];
                pq.push(tiii(-cost[i][gas + buy - dist[vx][i]], gas + buy - dist[vx][i], i));
            }
        }
    }
}

int main() {
    int tt;
    scanf(" %d", &tt);
    while (tt--) {
        scanf(" %d %d %d %d", &n, &m, &s, &t);
        for (int i = 1; i <= n; i++)
            adj[i].clear(), station[i] = false;
        for (int i = 0; i < m; i++) {
            int a, b, f;
            scanf(" %d %d %d", &a, &b, &f);
            adj[a].pb(pii(f, b));
            adj[b].pb(pii(f, a));
        }
        for (int i = 1; i <= s; i++) {
            int x, p;
            scanf(" %d %d", &x, &p);
            mp[x] = i;
            //printf("vx %d -> posto %d\n", x, i);
            price[i] = p;
            //dijkstra(x);
            station[x] = true;
        }
        for (int i = 1; i <= n; i++)
            if (station[i]) dijkstra(i);
        scanf(" %d %d", &c, &d);
        mp[d] = ++s;
        //printf("vx %d -> posto %d\n", d, s);
        dijkstra(d);
        price[mp[d]] = 0;
        djalma(mp[c]);
        printf("%d\n", cost[mp[d]][0]);
    }
}

