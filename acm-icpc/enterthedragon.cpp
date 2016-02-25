#include <bits/stdc++.h>
#define MAX 1000005
using namespace std;

int p[MAX], last[MAX], ans[MAX], first[MAX], rain[MAX];

int find (int v) {
    if (p[v] == v) return v;
    return p[v] = find (p[v]);
}

int main () {
    int t, n, m, s;
    bool ok;
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d %d", &n, &m);
        ok = true, s = 0;
        for (int i = 0; i <= n+1; i++) last[i] = 0;

        p[0] = 1, p[m+1] = m+1;

        for (int i = 1; i <= m; i++) {
            scanf (" %d", &rain[i]);
            if (rain[i]) p[i] = i+1;
            else p[i] = i;
            ans[i] = 0;
        }

        for (int i = 1; i <= m; i++) {
            if (rain[i]) {
                int k = find (last[rain[i]]);
                if (k > i) ok = false;
                else last[rain[i]] = i, ans[k] = rain[i], p[k] = k+1;
            } else first[s++] = i;
        }

        if (!ok) printf ("NO\n");
        else {
            printf ("YES\n");
            for (int i = 0; i < s; i++)
                printf ("%d%c", ans[first[i]], i != s-1 ? ' ' : '\n');
        }
    }
}
