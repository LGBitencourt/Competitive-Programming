#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, sum = 0;
int pai[505];

struct edge {
    int x, y, d;
} E[130000];

bool compare (edge a, edge b) { return a.d < b.d; }

int find (int v) {
    if (pai[v] == -1) return v;
    return pai[v] = find (pai[v]);
}

bool join (int a, int b) {
    if (find(a) != find(b)) {
        pai[find(a)] = find(b);
        return true;
    }
    return false;
}

int main () {
    scanf (" %d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        pai[i] = -1;
    for (int i = 0; i < m; i++)
        scanf (" %d %d %d", &E[i].x, &E[i].y, &E[i].d);
    sort (E, E + m, compare);
    for (int i = 0; i < m; i++)
        if (join (E[i].x, E[i].y))
            sum += E[i].d;
    printf ("%d\n", sum);
}
