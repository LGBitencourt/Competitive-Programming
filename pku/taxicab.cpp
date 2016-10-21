#include <iostream>
#include <algorithm>
#include <map>
#include <utility>
#include <vector>
#include <climits>
#include <string>

#define pb push_back

using namespace std;

/////////////////0123456789
const int MAXN = 504;
const int MAXM = 10005;

struct ride {
    int h, m, a, b, c, d;
    int id, id_t;
} r[MAXN];

int turn, n;
int ma[MAXM], mb[MAXM], seen[MAXM];
vector<int> adj[MAXM];

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

int max_matching() {
    int m = 0;
    for (int i = 0; i < 3000; i++) {
        turn++;
        if (ma[i] == -1 && augment(i)) m++;
    }
    return m;
}

int d(int i, int j) {
    return abs(r[i].c - r[j].a) + abs(r[i].d - r[j].b);
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);

        for (int i = 0; i < MAXM; i++)
            adj[i].clear(), ma[i] = mb[i] = -1;

        for (int i = 0; i < n; i++) {
            scanf(" %d:%d %d %d %d %d", 
                    &r[i].h, &r[i].m, &r[i].a, &r[i].b, &r[i].c, &r[i].d);
            r[i].id = 60 * r[i].h + r[i].m;
            int k = abs(r[i].a - r[i].c) + abs(r[i].b - r[i].d);
            r[i].id_t = r[i].id + k;;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (r[j].id >= r[i].id_t + d(i, j) + 1) {
                    adj[i].pb(j + 3000);
                    adj[j + 3000].pb(i);
                }
            }
        }
        printf("%d\n", n - max_matching());
    }
}

