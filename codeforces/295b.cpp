#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

lli dist[505][505][505], adj[505][505], ans[505];
int n, e[505];

void fw (int n) {
    int x = 1;
    for (int k = 1; k <= n; k++) {
        lli sum = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                dist[i][j][k] = min (dist[i][j][k-1],
                        dist[i][k][k-1] + dist[k][j][k-1]);
                if (i <= k && j <= k)
                    sum += dist[i][j][k];
            }
        ans[x++] = sum;
    }
}

int main () {
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf (" %lld", &adj[i][j]);
    for (int i = 1; i <= n; i++)
        scanf (" %d", e + i);
    reverse (e + 1, e + n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j][0] = adj[e[i]][e[j]];
    fw (n);
    for (int i = n; i >= 1; i--)
        printf ("%lld%c", ans[i], i > 1 ? ' ' : '\n');
}
