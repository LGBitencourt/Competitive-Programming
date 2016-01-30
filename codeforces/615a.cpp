#include <bits/stdc++.h>
using namespace std;

int bulbs[105];

int main () {
    int n, m, s, x;
    scanf (" %d %d", &n, &m);
    for (int i = 0; i < n; i++) {
       scanf (" %d", &x);
       for (int j = 0; j < x; j++) {
            scanf (" %d", &s);
            bulbs[s] = 1;
       }
    }
    bool f = true;
    for (int i = 1; i <= m; i++)
        if (bulbs[i] == 0) f = false;
    if (f) printf ("YES\n");
    else printf ("NO\n");
}
