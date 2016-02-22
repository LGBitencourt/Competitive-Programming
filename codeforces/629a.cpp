#include <bits/stdc++.h>
using namespace std;

char c[105][105];

int main () {
    int n, t = 0;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf (" %c", &c[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (c[i][j] == 'C') {
                for (int k = 0; k < n; k++)
                    if (k != i && c[k][j] == 'C') t++;
                for (int k = 0; k < n; k++)
                    if (k != j && c[i][k] == 'C') t++;
            }
    printf ("%d\n", t/2);
}
