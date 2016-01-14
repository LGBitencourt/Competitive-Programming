#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;

struct bx {
    double b, h, w, d;
} box[10000000];

int main () {
    int t, n;
    double v, vt, hmax;
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d", &n);
        vt = hmax = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %lf %lf %lf %lf", &box[i].b, &box[i].h, &box[i].w, &box[i].d);
            vt += box[i].h * box[i].w * box[i].d;
            hmax = max (hmax, box[i].b + box[i].h);
        }
        scanf (" %lf", &v);
        if (v - vt > -eps)
            printf ("OVERFLOW\n%s", !t ? "" : "\n");
        else {
            double l = 0, h = hmax, mid;
            while (h - l > eps) {
                mid = (l + h) / 2, vt = 0;
                for (int i = 0; i < n; i++) {
                    if (mid - box[i].b > -eps) {
                        if (box[i].b + box[i].h > mid - eps)
                            vt += (mid - box[i].b) * box[i].w * box[i].d;
                        else
                            vt += box[i].h * box[i].w * box[i].d;
                    }
                }
                if (vt - v > -eps) h = mid - eps;
                else l = mid;
            }
            printf ("%.2lf\n%s", l, !t ? "" : "\n");
        }
    }
}
