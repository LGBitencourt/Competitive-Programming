#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const double eps = 1e-9;
const int inf = INT_MAX;
/////////////////0123456789
const int MAXN = 10004;
const int modn = 1000000007;

int ans[20][20];
int dx[] = {1, -1, 0, 0},
    dy[] = {0, 0, 1, -1};

void bfs(int n) {
    queue<pii> q;
    q.push(pii(n, n));
    ans[n][n] = n;
    while (q.size()) {
        pii c = q.front();
        q.pop();
        if (ans[c.ff][c.ss] == 0) continue;
        for (int i = 0; i < 4; i++) {
            int x = c.ff + dx[i], y = c.ss + dy[i];
            if (ans[x][y] < ans[c.ff][c.ss]) {
                ans[x][y] = ans[c.ff][c.ss] - 1;
                q.push(pii(x, y));
            }
        }
    }
}

int main() {
    int n;
    scanf(" %d", &n);
    memset(ans, -1, sizeof ans);
    bfs(n);
    for (int i = 0; i <= 2 * n; i++) {
        bool f = false;
        for (int j = 0; j <= 2 * n; j++) {
            if (ans[i][j] == 0) f = true;
            if (ans[i][j] == -1) printf(" ");
            else printf("%d", ans[i][j]);
            if (f && ans[i][j + 1] == -1) break;
            printf(" ");
        }
        puts("");
    }
}

