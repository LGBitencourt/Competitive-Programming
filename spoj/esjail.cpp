#include <bits/stdc++.h>
#define MAX 100005
using namespace std;

int ck[MAX];
bool visited[MAX], n_key[MAX];
vector<int> adj[MAX];
int n, k, m, a, b;
queue<int> q;

bool bfs () {
    visited[0] = true;
    q.push (0);

    while (!q.empty()) {
        int x = q.front ();
        q.pop ();

        if (ck[x] != -1) {
            n_key[ck[x]] = false;
            if (visited[ck[x]]) q.push (ck[x]);
        }

        for (int i = 0; i < adj[x].size(); i++) {
            int aux = adj[x][i];
            if (!visited[aux]) {
                visited[aux] = true;
                if (!n_key[aux]) q.push (aux);
            }
        }
    }
}

int main () {
    while (scanf (" %d %d %d", &n, &k, &m) && n >= 0) {
        for (int i = 0; i < n; i++) {
            n_key[i] = false;
            visited[i] = false;
            ck[i] = -1;
            adj[i].clear();
        }
        for (int i = 0; i < k; i++) {
            scanf (" %d %d", &a, &b);
            a--, b--;
            ck[a] = b;
            n_key[b] = true;
        }
        for (int i = 0; i < m; i++) {
            scanf (" %d %d", &a, &b);
            a--, b--;
            adj[a].push_back (b);
            adj[b].push_back (a);
        }
        bfs ();
        printf ("%c\n", visited[n-1] ? 'Y' : 'N');
    }
}
