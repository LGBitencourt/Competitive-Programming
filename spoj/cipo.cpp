#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, sum;
struct edge {
    int u, v, d;
} E[2000005];
int pai[1005];

bool compare (edge a, edge b) { return a.d < b.d; }

int find (int v) {
    if (pai[v] == -1)
        return v;
    return pai[v] = find (pai[v]);
}

bool join (int a, int b) {
    if (find (a) != find (b)) {
        pai[find (a)] = find (b);
        return true;
    }
    return false;
}

int main () {
    int t = 1;
    while (scanf (" %d %d", &n, &m) != EOF) {
        sum = 0;
        for (int i = 0; i <= n; i++)
            pai[i] = -1;
        for (int i = 0; i < m; i++)
            scanf (" %d %d %d", &E[i].u, &E[i].v, &E[i].d);
        sort (E, E + m, compare);
        for (int i = 0; i < m; i++)
            if (join (E[i].u, E[i].v))
                sum += E[i].d;
        printf ("Instancia %d\n%d\n\n", t++, sum);
    }
}
