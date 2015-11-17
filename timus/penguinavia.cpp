#include <bits/stdc++.h>

using namespace std;

char scheme[105][105];
int n, d, a, qd = 0, qa = 0;
vector<int> adj[105];
bool visited[105];
int pai[105], sz[105];

void dfs (int v) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i]])
            dfs (adj[v][i]);
}

int find (int v) {
    if (pai[v] == -1) return v;
    return pai[v] = find (pai[v]);
}

bool join (int a, int b) {
    a = find (a), b = find (b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap (a, b);
    pai[a] = b, sz[b] += sz[a];
    return true;
}

void make_edge (int v) {
    for (int i = 0; i < n; i++)
        if (adj[i].size() > 0 && visited[i] && join (v, i))
            scheme[v][i] = scheme[i][v] = 'a', qa++;
}

int main () {
    scanf (" %d %d %d", &n, &d, &a);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scheme[i][j] = '0';
        pai[i] = -1, visited[i] = false;
    }
    char x;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf (" %c", &x);
            if (j > i) continue;
            if (x == '1') {
                if (join (i, j))
                    adj[i].push_back(j), adj[j].push_back(i);
                else scheme[i][j] = scheme[j][i] = 'd', qd++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        if (!visited[i] && adj[i].size() > 0)
            dfs(i), make_edge(i);
    printf ("%d\n", d*qd + a*qa);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            putchar(scheme[i][j]);
        putchar('\n');
    }
}
