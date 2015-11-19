#include <bits/stdc++.h>

using namespace std;

char scheme[105][105];
long long n, d, a, qd = 0, qa = 0;
set<int> s;
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
    scanf (" %lld %lld %lld", &n, &d, &a);
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
                if (!join (i, j))
                    scheme[i][j] = scheme[j][i] = 'd', qd++;
            }
        }
    }
    int l = find (0);
    for (int i = 1; i < n; i++)
        if (pai[i] == -1 && i != l)
            qa++, scheme[l][i] = scheme[i][l] = 'a';

    printf ("%lld\n", d*qd + a*qa);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            putchar(scheme[i][j]);
        putchar('\n');
    }
}
