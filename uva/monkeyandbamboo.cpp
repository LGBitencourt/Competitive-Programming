#include <bits/stdc++.h>
using namespace std;

int main () {
    int tc, n, l, h;
    int rungs[100005];
    scanf (" %d", &tc);
    for (int t = 1; t <= tc; t++) {
        l = h = 0;
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf (" %d", rungs+i);
            if (rungs[i] > h) h = rungs[i];
        }
        while (l != h) {
            bool can = true;
            int mid = (l+h)/2, last = 0;
            int m = mid;
            for (int i = 0; i < n; i++) {
                if (rungs[i] - last == m) m--;
                else if (rungs[i] - last > m) can = false;
                last = rungs[i];
            }
            if (can && m >= 0) h = mid;
            else l = mid + 1;
        }
        printf ("Case %d: %d\n", t, l);
    }
}
