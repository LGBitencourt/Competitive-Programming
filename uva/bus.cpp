#include <cstdio>
#include <algorithm>

using namespace std;

int m[105], a[105];

int main () {
    int n, d, r, sum;
    while (scanf (" %d %d %d", &n, &d, &r), n != 0) {
        sum = 0;
        for (int i = 0; i < n; i++)
            scanf (" %d", &m[i]);
        for (int i = 0; i < n; i++)
            scanf (" %d", &a[i]);
        sort (m, m + n);
        sort (a, a + n);
        for (int i = 0; i < n; i++) {
            int k = m[i] + a[n - 1 - i] - d;
            if (k > 0)
                sum += k;
        }

        printf ("%d\n", sum * r);
    }
}
