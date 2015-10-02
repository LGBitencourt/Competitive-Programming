#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

int c, r, mx;
map<string, int> index;
string name, x, y;
vector<int> adj[5005];

bool visited[5005];

void dfs(int v, int m) {
    visited[v] = true;
    if (m > mx) mx = m;
    for (vector<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++it)
        if (!visited[*it])
            dfs(*it, m + 1);
}

int main () {
    ios::sync_with_stdio(false);
    while (cin >> c >> r, c != 0) {
        mx = 0;
        for (int i = 0; i < c; i++) {
            cin >> name;
            index.insert(make_pair(name, i));
        }
        for (int i = 0; i < r; i++) {
            cin >> x >> y;
            adj[index[x]].push_back(index[y]);
        }
        for (int i = 0; i < c; i++)
            dfs(i, 1);
        cout << mx << '\n';
    }
}
