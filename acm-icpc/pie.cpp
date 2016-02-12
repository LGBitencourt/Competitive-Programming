#include <bits/stdc++.h>
#define MAX 10005
#define eps 1e-5
using namespace std;

int main () {
    int tc, n, f, cnt;
    double pi = acos (-1), l, h, m;
    double v[MAX];
    scanf (" %d", &tc);
    while (tc--) {
        l = h = 0;
        scanf (" %d %d", &n, &f);
        for (int i = 0; i < n; i++) {
            scanf (" %lf", &v[i]);
            v[i] = pi * v[i] * v[i];
            h = max (h, v[i]);
        }
        while (h - l > eps) {
            m = (h + l)/2.0, cnt = 0;
            for (int i = 0; i < n; i++)
                cnt += v[i]/m;
            if (cnt >= f + 1) l = m;
            else h = m - eps;
        }
        printf ("%.4lf\n", l);
    }
}
