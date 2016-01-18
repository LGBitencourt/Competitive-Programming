#include <bits/stdc++.h>
#define eps 1e-8
using namespace std;
typedef long long ll;

ll v[10005];

int main () {
    int t, n, k;
    scanf (" %d", &t);
    while (t--) {
        ll l = 0, h = 0, mid, c;
        double x;
        scanf (" %d %d", &n, &k);
        for (int i = 0; i < n; i++)
            scanf (" %lf", &x), v[i] = (int) (x*100), h += v[i];
        while (l < h) {
            mid = (l+h+1)/2;
            c = 0;
            for (int i = 0; i < n; i++)
                c += (v[i] / mid);
            if (c >= k) l = mid;
            else h = mid - 1;
        }
        printf ("%.2lf\n%s", l/100.0, !t ? "" : "\n");
    }
}
