#include <cstdio>

#define MAX 100005
#define MAXI 200010

int pai[MAXI], q[MAXI], sum[MAXI];

int find (int v) {
    if (pai[v] == MAX + v) return MAX + v;
    return pai[v] = find (pai[v]);
}

void join (int a, int b) {
    int pa = find (a), pb = find (b);
    if (pa != pb) {
        q[pb] += q[pa], sum[pb] += sum[pa];
        pai[pa] = pb;
    }
}

void op (int np, int v) {
    int pnp = find (np);
    q[pnp] += 1, sum[pnp] += v;
    pai[v] = pnp;
}

int main () {
    int n, m;
    scanf (" %d %d", &n, &m);
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
