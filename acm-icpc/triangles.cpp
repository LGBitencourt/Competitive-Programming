#include <cstdio>
#include <algorithm>
#include <complex>

using namespace std;

struct P {
    long long int x, y, norm;
};

P anc;

bool compare (P a, P b) {
    if (a.norm != b.norm) return a.norm < b.norm;
    return a.x < b.x;
}

int main () {
    int n, t;
    while (scanf (" %d", &n), n != 0) {
        t = 0;
        P ps[1005], p[1005];
        for (int i = 0; i < n; i++) {
            long long int x, y;
            scanf (" %lld %lld", &x, &y);
            p[i].x = ps[i].x = x;
            p[i].y = ps[i].y = y;
        }
        for (int i = 0; i < n; i++) {
            anc = p[i];
            for (int j = 0; j < n; j++)
                ps[j].norm = (anc.x - ps[j].x)*(anc.x - ps[j].x) + (anc.y - ps[j].y)*(anc.y - ps[j].y);
            sort (ps, ps + n, compare);
            int k = 1;
            for (int j = 1; j < n; j++) {
                if (ps[j].norm == ps[j-1].norm) {
                    k++;
                } else {
                    t += k*(k-1)/2;
                    k = 1;
                }
            }
            t += k*(k-1)/2;
        }
        printf ("%d\n", t);
    }
}
