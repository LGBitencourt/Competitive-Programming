#include <bits/stdc++.h>
#define MAX 505
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

int s[MAX][MAX];
int x[4] = {1, -1, 0, 0}, y[4] = {0, 0, 1, -1};
int dp[MAX][MAX];
int r, c;
queue<pii> q;

int main () {
    int t, l, h, m;
    scanf (" %d", &t);
    while (t--) {
        l = h = 1;
        scanf (" %d %d", &r, &c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                scanf (" %d", &s[i][j]);
                if (s[i][j] < 0) h -= s[i][j];
            }
        while (l != h) {
            m = (l + h)/2;
            dp[0][0] = m;
            for (int i = 1; i < c; i++) {
                dp[0][i] = dp[0][i-1];
                dp[0][i] = dp[0][i] > 0 ? dp[0][i] + s[0][i] : -1000000;
            }
            for (int i = 1; i < r; i++) {
                dp[i][0] = dp[i-1][0];
                dp[i][0] = dp[i][0] > 0 ? dp[i][0] + s[i][0] : -1000000;
            }
            for (int i = 1; i < r; i++)
                for (int j = 1; j < c; j++) {
                    dp[i][j] = max (dp[i-1][j], dp[i][j-1]);
                    dp[i][j] = dp[i][j] > 0 ? dp[i][j] + s[i][j] : -1000000;
                }
            if (dp[r-1][c-1] > 0) h = m;
            else l = m + 1;
        }
        printf ("%d\n", l);
    }
}
