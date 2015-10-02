#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int c, r, mx, path;
map<string, int> index;
string name, x, y;
vector<int> adj[5005];

bool visited[5005];

void dfs(int v) {
    path++;
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++)
        if (!visited[adj[v][i]])
            dfs(adj[v][i]);
}

void zera() {
    for (int i = 0; i < c; i++)
        visited[i] = false;
    index.clear();
    for (int i = 0; i < c; i++)
        adj[i].clear();
}

int main () {
    ios::sync_with_stdio(false);
    while (cin >> c >> r, c != 0) {
        mx = 0;
        zera();
        for (int i = 0; i < c; i++) {
            cin >> name;
            index.insert(make_pair(name, i));
        }
        for (int i = 0; i < r; i++) {
            cin >> x >> y;
            adj[index[x]].push_back(index[y]);
            adj[index[y]].push_back(index[x]);
        }
        for (int i = 0; i < c; i++) {
            if (!visited[i]) {
                path = 0;
                dfs(i);
                if (path > mx) mx = path;
            }
        }
        cout << mx << '\n';
    }
}
