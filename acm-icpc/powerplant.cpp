#include <cstdio>
#include <algorithm>

using namespace std;

struct P {
    int u, v, c;
} p[4000005];

int n, m, k, sum;

int pai[2005], pp[2005];

bool compare (P a, P b) { return a.c < b.c; }

int find (int v) {
    if (pai[v] == -1) return v;
    return pai[v] = find(pai[v]);
}

bool join (int a, int b) {
    if (!pp[find(a)] && find(a) != find(b)) {
        pai[find(a)] = find(b);
        return true;
    } else if (!pp[find(b)] && find(a) != find(b)) {
        pai[find(b)] = find(a);
        return true;
    }
    return false;
}

int main () {
    int t;
    scanf (" %d", &t);
    for (int j = 1; j <= t; j++) {
        sum = 0;
        scanf (" %d %d %d", &n, &m, &k);
        for (int i = 0; i <= n; i++)
            pai[i] = -1, pp[i] = 0;

        for (int i = 0; i < k; i++) {
            int x;
            scanf (" %d", &x);
            pp[x] = 1;
        }

        for (int i = 0; i < m; i++)
            scanf (" %d %d %d", &p[i].u, &p[i].v, &p[i].c);

        sort(p, p + m, compare);

        for (int i = 0; i < m; i++)
            if (join(p[i].u, p[i].v))
                sum += p[i].c;

        printf ("Case #%d: %d\n", j, sum);
    }
}
