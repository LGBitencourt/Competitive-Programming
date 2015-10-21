#include <cstdio>
#include <algorithm>

#define MAX 10004

using namespace std;

int pai[MAX], sz[MAX];

struct E { int u, v, c; } e[MAX];

bool compare (E a, E b) { return a.c < b.c; }

int find (int v) {
    if (pai[v] == -1) return v;
    return pai[v] = find(pai[v]);
}

bool join (int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap(a, b);
    pai[a] = b, sz[b] += sz[a];
    return true;
}

int main () {
    int n, m, t = 0;
    scanf (" %d %d", &n, &m);
    for (int i = 0; i <= n; i++)
        pai[i] = -1, sz[i] = 1;
    for (int i = 0; i < m; i++)
        scanf (" %d %d %d", &e[i].u, &e[i].v, &e[i].c);
    sort (e, e + m, compare);
    for (int i = 0; i < m; i++)
        if (join(e[i].u, e[i].v))
            t += e[i].c;
    printf ("%d\n", t);
}
