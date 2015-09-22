#include <cstdio>
#include <utility>
#include <algorithm>
#include <climits>
#include <cstring>

#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

pii F[55];
int c, f;
int mpd[55][1005];

int pd (int i, int ch) {
    if (ch < 0) return INT_MIN;
    if (i == f) return 0;
    if (mpd[i][ch] != -1) return mpd[i][ch];

    int r1 = INT_MIN, r2;
    if (ch - F[i].ff >= 0)
        r1 = F[i].ss + pd (i + 1, ch - F[i].ff);
    r2 = pd (i + 1, ch);

    return mpd[i][ch] = max(r1, r2);
}

int main () {
    int t = 1;
    while (scanf(" %d %d", &c, &f), c != 0) {
        memset(mpd, -1, sizeof mpd);
        for (int i = 0; i < f; i++) {
            int n, d;
            scanf(" %d %d", &n, &d);
            F[i] = pii(n, d);
        }
        printf ("Teste %d\n%d\n\n", t++, pd(0, c));
    }
}
