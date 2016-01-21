#include <bits/stdc++.h>
using namespace std;

char c[10005][10005];
int a[10005][2];
int n, m;

int main () {
    scanf (" %d %d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf (" %s", c[i]);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            a[i][0] += c[j][i] == 'W';
            a[i][1] += c[j][i] == 'E';
        }
    }
    for (int i = 1; i < n; i++)
        a[i][0] += a[i - 1][0], a[i][1] += a[i - 1][1];
    int mi = 1e9, l, aux;
    for (int i = 0; i < n; i++) {
        aux = a[i][1] + a[n-1][0] - a[i][0];
        if (aux < mi) mi = aux, l = i+1;
    }
    if (a[n-1][0] <= mi) l = 0;
    printf ("%d %d\n", l, l+1);
}
