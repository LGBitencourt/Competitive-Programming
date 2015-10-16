#include <cstdio>
#include <algorithm>
#include <complex>

using namespace std;

bool compare (P a, P b) {
    if (abs(a) != abs(b)) return abs(a) < abs(b);
    else return a.x < b.x;
}

int main () {
    int n;
    while (scanf (" %d", &n), n != 0) {
        int t = 0;
        complex<int> p[1005];
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf (" %d %d", &x, &y);
        }
        for (int i = 0; i < n; i++) {
            p[1004] = p[i];
            sort(p, p + n, compare);
            for (int i = 1; i < n; i++)
                if (p[i].norm == p[i-1].norm)
                    t += n * (n - 1) / 2;
        }
        printf ("%d\n", t);
    }
}
