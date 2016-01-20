#include <bits/stdc++.h>
#define MAX 10005
#define ff first
#define ss second
using namespace std;
typedef pair<int, int> pii;

pii acc[MAX];
char C[MAX][105];

int main () {
    int n, m;
    scanf ("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf (" %c", &C[i][j]);
        }
    }
    for (int i = 0; i <= n; i++)
        acc[i].ff = acc[i].ss = 0;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= m; i++) {
            if (C[i][j] == 'W') acc[j].ff++;
            else acc[j].ss++;
        }
    }
    for (int i = 1; i <= n; i++)
        acc[i].ff += acc[i-1].ff, acc[i].ss += acc[i-1].ss;
    int mi = 1e9, l, r;
    mi = min (mi, acc[n].ss);
    mi = min (mi, acc[n].ff);
    for (int i = 1; i < n; i++)
        mi = min (mi, acc[i].ss + acc[n].ff - acc[i].ff);
    if (mi == acc[n].ff) l = 0, r = 1;
    else {
        bool f = false;
        for (int i = 1; i < n; i++) {
            if (mi == acc[i].ss + acc[n].ff - acc[i].ff) {
                l = i, r = i + 1, f = true;
                break;
            }
        }
        if (!f && mi == acc[n].ss) l = n, r = n + 1;
    }
    printf ("%d %d\n", l, r);
}
