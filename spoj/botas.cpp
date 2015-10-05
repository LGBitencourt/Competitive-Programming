#include <cstdio>
#include <algorithm>

using namespace std;

int main () {
    int n, d, e, p;
    int D[10005], E[10005];
    while (scanf(" %d", &n) != EOF) {
        d = e = p = 0;
        for (int i = 0; i < n; i++) {
            int s; char c;
            scanf(" %d %c", &s, &c);
            if (c == 'D') D[d++] = s;
            else E[e++] = s;
        }
        sort(D, D + d);
        sort(E, E + e);
        d--, e--;
        while (e >= 0 && d >= 0) {
            if (D[d] == E[e]) p++, d--, e--;
            else if (D[d] > E[e]) d--;
            else e--;
        }
        printf("%d\n", p);
    }
}
