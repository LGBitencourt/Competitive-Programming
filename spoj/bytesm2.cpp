#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int mpd[105][105];
int map[105][105];

int pd (int i, int j) {
    if (i == n || j == m || j < 0) return 0;
    if (mpd[i][j] != -1) return mpd[i][j];
    mpd[i][j] = map[i][j] + max(pd(i + 1, j), 
        max(pd(i + 1, j + 1), pd(i + 1, j - 1)));
    return mpd[i][j];    
}

int main() {
    int t;
    scanf(" %d", &t);
    while (t--) {
        for (int i = 0; i < 105; i++)
            for (int j = 0; j < 105; j++)
                mpd[i][j] = -1;
        scanf (" %d %d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf(" %d", &map[i][j]);
        int k = INT_MIN;
        for (int j = 0; j < m; j++)
            k = max(k, pd (0, j));
        printf("%d\n", k);
    }
}
