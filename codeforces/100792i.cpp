#include <bits/stdc++.h>

using namespace std;

int v[2100];

int main () {
    int n, x, y;
    bool f = false;
    scanf (" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf (" %d %d", &x, &y);
        for (int j = x; j <= y; j++)
            v[j] = 1;
    }
    int i, j, d;
    i = 1, d = j = 0;
    while (j < 181) d += v[j++];
    if (d > 90) f = true;
    while (i < 1827) {
        if (v[i++]) d--;
        d += v[j++];
        if (d > 90) f = true;
    }
    if (f) printf ("No\n");
    else printf ("Yes\n");
}
