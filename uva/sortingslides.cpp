#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

/////////////////0123456789
const int MAXN = 1004;

int turn, n;
int seen[MAXN], ma[MAXN], mb[MAXN], edges[MAXN], ans[MAXN];
vector<int> adj[MAXN];

struct rect {
    int x_min, x_max, y_min, y_max;
    rect(){}
    rect(int x_mi, int x_ma, int y_mi, int y_ma) {
        x_min = x_mi;
        x_max = x_ma;
        y_min = y_mi;
        y_max = y_ma;
    }
    bool inside(int x, int y) {
        if (x > x_min && x < x_max
                && y > y_min && y < y_max)
            return true;
        return false;
    }
} r[MAXN];

bool augment(int u) {
    if (seen[u] >= turn) return false;
    seen[u] = turn;
    for (int v : adj[u]) {
        if (mb[v] == -1 || augment(mb[v])) {
            ma[u] = v;
            mb[v] = u;
            return true;
        }
    }
    return false;
}

int max_matching() {
    int m = 0;
    for (int i = 0; i < MAXN; i++)
        ma[i] = mb[i] = -1;
    for (int i = 0; i < n; i++) {
        turn++;
        if (ma[i] == -1 && augment(i))
            m++;
    }
    return m;
}

int main() {
    int tc = 1;
    while (scanf(" %d", &n), n != 0) {
        int x, y;
        for (int i = 0; i < MAXN; i++)
            adj[i].clear(), ans[i] = -1;
        for (int i = 0; i < n; i++) {
            int a, b, c, d;
            scanf(" %d %d %d %d", &a, &b, &c, &d);
            r[i] = rect(a, b, c, d);
        }
        for (int i = 0; i < n; i++) {
            scanf(" %d %d", &x, &y);
            for (int j = 0; j < n; j++)
                if (r[j].inside(x, y)) {
                    adj['A' + j].pb(i);
                    adj[i].pb('A' + j);
                }                  
        }
        printf("Heap %d\n", tc++);

        if (max_matching() >= n) {
            for (int i = 0; i < n; i++)
                edges[i] = ma[i];
            for (int i = 0; i < n; i++) {
                adj[i].erase(find(adj[i].begin(), adj[i].end(), edges[i]));
                adj[edges[i]].erase(find(adj[edges[i]].begin(), adj[edges[i]].end(), i));
                if (max_matching() < n) ans[edges[i]] = i;
                adj[i].pb(edges[i]);
                adj[edges[i]].pb(i);
            }
        }
        bool f = true;
        for (char c = 'A'; c <= 'Z'; c++) {
            if (ans[c] != -1) {
                if (!f) printf(" ");
                printf("(%c,%d)", c, ans[c] + 1);
                f = false;
            }
        }
        if (f) printf("none");
        puts("\n");
    }
}

