#include <bits/stdc++.h>
using namespace std;

char c[100005];
int p[100005][2];

int main () {
    int n, um, pum;
    n = um = pum = 0;
    while (scanf (" %c", &c[n]) != EOF) {
        if (c[n] == '1') p[um++][0] = n, pum++;
        n++;
    }
    pum--;
    for (int i = n-1; i >= 0; i--)
        if (c[i] == '1')
            p[--pum][1] = i;
    int mi = INT_MAX;
    for (int i = 0; i <= um; i++)
        mi = min (mi, min (2*p[i][0]+n-p[i][1], 2*(n-p[i][1])+p[i][0]));
    if (um == 0) mi = 0;
    printf ("%d\n", 4*um + 7*mi);
}
