#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
/////////////////0123456789
const int MAXN = 214;

int n, turn;
pii s[MAXN], t[MAXN];
int ma[MAXN], mb[MAXN], seen[MAXN];
vector<int> adj[MAXN];

bool augment(int u) {
    if (seen[u] >= turn) return false;
    seen[u] = turn;
    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (mb[v] == -1 || augment(mb[v])) {
            ma[u] = v;
            mb[v] = u;
            return true;
        }
    }
    return false;
}

int max_matching(int k) {
    int m = 0;
    turn = 0;
    for (int i = 0; i < n; i++) {
        adj[i].clear(), adj[n + i].clear();
        ma[i] = mb[i] = ma[n + i] = mb[n + i] = -1;
        seen[i] = seen[n + i] = false;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (abs(s[i].ff - t[j].ff) + abs(s[i].ss - t[j].ss) <= k) {
                adj[i].pb(n + j), adj[n + j].pb(i);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        turn++;
        if (ma[i] == -1 && augment(i)) m++;
    }
    return m;
}

int main() {
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        s[i] = pii(x, y);
    }
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf(" %d %d", &x, &y);
        t[i] = pii(x, y);
    }
    int l = 0, h = (int) 4e8 + 10;
    while (l != h) {
        int m = (l + h) / 2;
        int k = max_matching(m);
        if (k == n) h = m;
        else l = m + 1;
    }
    printf("%d\n", l);
}

