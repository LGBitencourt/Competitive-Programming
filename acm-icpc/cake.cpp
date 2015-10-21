#include <cstdio>

char q[2005];

int main () {
    int t, n, k, m;
    scanf (" %d", &t);
    for (int z = 1; z <= t; z++) {
        scanf (" %d %d %d", &n, &m, &k);
        for (int i = 0; i < 2*n; i++)
            scanf (" %c", &q[i]);
        int i = 0; char c;
        while (m > 0) {
            int x = 0;
            if (m <= k) {
                c = q[i];
                break;
            }
            m--, x++;
            if (q[i] == q[i+1]) {
                while (m % k != 0 && x < k) m--, x++;
            } else {
                while (m % (k+1) != 0 && x < k) m--, x++;
            }
            i++;
        }
        printf ("Case #%d: %c\n", z, c);
    }
}
