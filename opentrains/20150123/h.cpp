#include <bits/stdc++.h>
using namespace std;

int v[10000];

int main () {
    int n;
    while (scanf ("%d", &n) && n != 0) {
        for (int i = 0; i < n; i++) {
            scanf ("%d", &v[i]);
        }
        sort (v, v+n);
        bool f = false;
        for (int i = 0; i <= n-1; i++) {
            if (i == n-1) {
                if (1422 - v[i] > 100) {
                    printf ("IMPOSSIBLE\n");
                    f = true;
                    break;
                }
            }
            else {
                if (v[i+1]-v[i] > 200) {
                    printf ("IMPOSSIBLE\n");
                    f = true;
                    break;
                }
            }

        }
        if (!f) printf ("POSSIBLE\n");
    }
}

