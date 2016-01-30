#include <bits/stdc++.h>
#define MAX 100
using namespace std;

bool visited[MAX];
int mA[MAX], mB[MAX];
vector<int> adj[MAX];
int A[3] = {1, 3, 5}, B[3] = {2, 4, 6};

bool find_increase (int v) {
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i]] || find_increase (adj[v][i])) {
            visited[adj[v][i]] = true;
            mA[v] = adj[v][i], mB[adj[v][i]] = v;
            return true;
        }
    return false;
}

int main () {
    int n, m;
    scanf (" %d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf (" %d %d", &x, &y);
        adj[x].push_back (y);
        adj[y].push_back (x);
    }
    for (int i = 0; i < 3; i++) {
        find_increase (A[i]);
    }
    for (int i = 1; i < 7; i++)
        printf ("%d %d\n", mA[i], mB[i]);
}
