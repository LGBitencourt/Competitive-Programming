#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int k, w;
int pai[100005];
map<int, int> em;
vector<int> adj[100005];

int find (int v) {
    if (pai[v] == -1) return v;
    return pai[v] = find (pai[v]);
}

bool join (int a, int b) {
    if (find (a) != find (b)) {
        pai[find (a)] = find (b);
        return true;
    }
    return true;
}

int main () {
    while (scanf (" %d %d", &k, &w), k != 0) {
        for (int i = 0; i < 100005; i++)
            pai[i] = -1;

        for (int i = 0; i < k; i++) {
            int u, v;
            scanf (" %d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
}
