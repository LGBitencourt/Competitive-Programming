#include <bits/stdc++.h>
using namespace std;

int b[2][1005];

int main () {
    int n, t, tc = 1;
    while (scanf (" %d", &n) && n != 0) {
        memset (b, 0, sizeof b);
        t = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int a;
                scanf (" %d", &a);
                b[0][i] += a, b[1][j] += a, t += a;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += abs (b[1][i] - b[0][i]);
        printf ("%d. %d %d\n", tc++, t, ans/2);
    }
}
