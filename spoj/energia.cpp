#include <cstdio>
#include <vector>

using namespace std;

int E, L, o, d, t = 0;
int mark[105];
vector<int> adj[105];

void dfs(int v) {
    mark[v] = 1;
    for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
        if (!mark[*it])
            dfs(*it);
}

int main() {
    while (scanf(" %d %d", &E, &L), E != 0 && L != 0) {
        int ok = 1;
        for (int i = 1; i < 105; i++) mark[i] = 0, adj[i].clear();
        for (int i = 0; i < L; i++) {
            scanf(" %d %d", &o, &d);
            adj[o].push_back(d);
            adj[d].push_back(o);
        }

        printf("Teste %d\n", ++t);

        dfs(o);

        for (int i = 1; i <= E; i++)
            if (mark[i] == 0) ok = 0;

        if (ok) printf("normal\n");
        else printf("falha\n");

        putchar('\n');
    }
}
