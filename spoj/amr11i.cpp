#include <bits/stdc++.h>

#define birth 0
#define death 1
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 71234;

struct event {
    int when, what, who;
    event() {}
    event(int e, int a, int o) {
        when = e, what = a, who = o;
    }
    bool operator< (const event &e) {
        if (when != e.when) return when < e.when;
        return what < e.what;
    }
};
event events[4 * MAXN];
int seg[4 * MAXN], depth[MAXN], pre[MAXN], pos[MAXN], turn, ans[MAXN];
bool seen[MAXN];
vector<int> adj[MAXN];

void update(int l, int r, int v, int x, int n) {
    if (l > v || r < v) return;
    if (l == r) {
        seg[n] = x;
        return;
    }
    int m = (l + r) / 2;
    update(l, m, v, x, 2 * n);
    update(m + 1, r, v, x, 2 * n + 1);
    seg[n] = max(seg[2 * n], seg[2 * n + 1]);
}

int query(int l, int r, int x, int y, int n) {
    if (l >= x && r <= y) return seg[n];
    if (l > y || r < x) return 0;
    int m = (l + r) / 2;
    return max(query(l, m, x, y, 2 * n),
            query(m + 1, r, x, y, 2 * n + 1));
}

void dfs(int u, int d) {
    depth[u] = d;
    pre[u] = turn++;
    seen[u] = true;
    for (int v : adj[u])
        if (!seen[v])
            dfs(v, d + 1);
    pos[u] = turn-1;
}

void clr() {
    turn = 0;
    for (int i = 0; i < MAXN; i++) {
        seen[i] = depth[i] = pre[i] = pos[i] = ans[i] = 0;
        adj[i].clear();
    }
    for (int i = 0; i < 4 * MAXN; i++)
        seg[i] = 0;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        clr();
        int m, p, h, d, e = 2;
        scanf(" %d", &m);
        scanf(" %d %d %d", &p, &h, &d);
        events[0] = event(h, birth, 0);
        events[1] = event(d, death, 0);
        for (int i = 1; i < m; i++) {
            scanf(" %d %d %d", &p, &h, &d);
            adj[p].pb(i), adj[i].pb(p);
            events[e++] = event(h, birth, i);
            events[e++] = event(d, death, i);
        }
        dfs(0, 0);
        sort(events, events + e);
        for (int i = 0; i < e; i++) {
            event x = events[i];
            if (x.what == birth)
                update(0, pos[0], pre[x.who], depth[x.who], 1);
            else ans[x.who] = query(0, pos[0], pre[x.who], pos[x.who], 1);
        }
        for (int i = 0; i < m; i++)
            printf("%d%c", ans[i] - depth[i], i == m - 1 ? '\n' : ' ');
    }
}

