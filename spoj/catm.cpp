#include <cstdio>
#include <algorithm>

using namespace std;

struct d {
    int u, d, l, r;
};

int main () {
    int n, m, t;
    scanf ("%d %d %d", &n, &m, &t);
    while (t--) {
        int rx, ry, gx, gy, gxx, gyy;
        scanf ("%d %d %d %d %d %d", &ry, &rx, &gy, &gx, &gyy, &gxx);
        d r, g1, g2;
        r.u = ry-1, r.d = n-ry, r.r = m - rx, r.l = rx-1;
        g1.u = gy-1 + abs(rx-gx), g1.d = n-gy + abs(rx-gx),
            g1.l = gx-1 + abs(ry-gy), g1.r = m-gx+abs(ry-gy);
        g2.u = gyy-1 + abs(rx-gxx), g2.d = n-gyy + abs(rx-gxx),
            g2.l = gxx-1 + abs(ry-gyy), g2.r = m-gxx+abs(ry-gyy);
        if (r.u < g1.u && r.u < g2.u)
            printf ("YES\n");
        else if (r.d < g1.d && r.d < g2.d)
            printf ("YES\n");
        else if (r.l < g1.l && r.l < g2.l)
            printf ("YES\n");
        else if (r.r < g1.r && r.r < g2.r)
            printf ("YES\n");
        else printf ("NO\n");
    }
}
