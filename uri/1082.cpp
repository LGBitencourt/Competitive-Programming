#include <cstdio>
#include <set>

using namespace std;

set<int> adj[30];
int marked[30];
int V, E, c;
char x, y;
set<char> p;

void dfs(int v) {
    marked[v] = 1;
    p.insert('a' + v);
    for (set<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
        if (!marked[*it])
            dfs(*it);
}

int main() {
    int T;
    scanf(" %d", &T);

    for (int t = 1; t <= T; t++) {
        for (int i = 0; i < 30; i++) adj[i].clear(), marked[i] = 0;
        c = 0;

        scanf(" %d %d", &V, &E);

        for (int i = 0; i < E; i++) {
            scanf(" %c %c", &x, &y);
            adj[x - 'a'].insert(y - 'a');
            adj[y - 'a'].insert(x - 'a');
        }

        printf("Case #%d:\n", t);

        for (int i = 0; i < V; i++) {
            p.clear();
            if (!marked[i]) {
                dfs(i);
                c++;
                for (set<char>::iterator it = p.begin(); it != p.end(); ++it)
                    printf("%c,", *it);
                putchar('\n');
            }
        }

        printf("%d connected components\n\n", c);

    }
}
