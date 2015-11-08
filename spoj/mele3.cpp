#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <climits>

#define ff first
#define ss second

using namespace std;

typedef pair<int, int> pii;

priority_queue<pii> q;
vector<pii> adj[1005];
int d[50005];

int mod (int n, int m) {
    if (!(n % m)) return n;
    return n % m;
}

void dijkstra () {
    while (!q.empty()) {
        int x = q.top().ss;
        q.pop();
        for (int i = 0; i < adj[x].size(); i++) {
            pii next = adj[x][i];
            if (d[next.ss] > d[x] + 3*next.ff - mod(d[x], 2*next.ff)) {
                d[next.ss] = d[x] + 3*next.ff - mod(d[x], 2*next.ff);
                q.push(pii(-d[next.ss], next.ss));
            }
        }
    }
}

int main() {
    int k, n;
    scanf (" %d %d", &k, &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf (" %d %d", &x, &y);
        if (y > x) swap(x, y);
        adj[x].push_back(pii(x-y, y));
        adj[y].push_back(pii(x-y, x));
    }
    for (int i = 0; i <= k; i++)
        d[i] = INT_MAX;
    q.push (pii(0, 1));
    d[1] = 0;
    dijkstra();
    printf ("%d\n", 5*d[k]);
}
