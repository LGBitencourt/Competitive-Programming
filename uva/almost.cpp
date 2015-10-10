#include <cstdio>

#define MAX 100005
#define MAXI 200010

int pai[MAXI], q[MAXI], sum[MAXI];

int find (int v) {
    if (pai[v] == -1) return v;
    return pai[v] = find (pai[v]);
}

void join (int a, int b) {
    int pa = find (a), pb = find (b);
    if (pa != pb) {
        q[pb] += q[pa], sum[pb] += sum[pa];
        pai[pa] = pb;
    }
}

void op (int v, int np) {
    int pv = find (v);
    q[pv] -= 1, sum[pv] -= v;
    int pnp = find (np);
    q[pnp] += 1, sum[pnp] += v;
    pai[v] = pnp;
}

int main () {
    int n, m;
    while (scanf (" %d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++)
            pai[MAX + i] = -1, pai[i] = MAX + i, q[MAX + i] = 1, sum[MAX + i] = i;
        while (m--) {
            int o, x, y;
            scanf (" %d %d", &o, &x);
            if (o == 3) {
                printf ("%d %d\n", q[find(x)], sum[find(x)]);
            } else {
                scanf (" %d", &y);
                if (o == 1)
                    join (x, y);
                else
                    op (x, y);
            }
        }
    }
}
