#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 512;

int n;
char s[2][MAXN];
bool seen[2][MAXN];

int dfs(int i, int j) {
    seen[i][j] = true;
    if (i == 0 && s[1][j] == '#' && !seen[1][j])
        return 1 + dfs(1, j);
    if (i == 0 && j < n - 1 && s[0][j + 1] == '#' && !seen[0][j + 1])
        return 1 + dfs(0, j + 1);
    if (i == 1 && s[0][j] == '#' && !seen[0][j])
        return 1 + dfs(0, j);
    if (i == 1 && j < n - 1 && s[1][j + 1] == '#' && !seen[1][j + 1])
        return 1 + dfs(1, j + 1);
    return 0;
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        int sj, si, k = 0;
        sj = inf;
        scanf(" %d", &n);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++) {
                seen[i][j] = false;
                scanf(" %c", &s[i][j]);
                if (s[i][j] == '#') {
                    k++;
                    if (j < sj) sj = j, si = i;
                }
            }
        if (k > 0 && dfs(si, sj) == k - 1) puts("yes");
        else puts("no");
    }
}

