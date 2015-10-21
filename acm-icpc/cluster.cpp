#include <cstdio>
#include <algorithm>

using namespace std;

int set[1000006];

int main () {
    int t, n, k;
    scanf (" %d", &t);
    for (int z = 1; z <= t; z++) {
        int c = 1;
        scanf (" %d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf (" %d", &set[i]);
        sort (set, set + n);
        for (int i = 1; i < n; i++)
            if (set[i] - set[i-1] > k)
                c++;
        printf ("Case #%d: %d\n", z, c);
    }
}
