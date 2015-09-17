#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
bool adj[5000][5000];
int degree[5000];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = adj[y][x] = true;
        degree[x]++, degree[y]++;
    }
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (adj[i][j])
                for (int k = j + 1; k <= n; k++)
                    if (adj[i][k] && adj[j][k])
                        ans = min(ans, degree[i] + degree[j] + degree[k]);
    if (ans == INT_MAX) cout << "-1\n";
    else cout << ans - 6 << '\n';
}
