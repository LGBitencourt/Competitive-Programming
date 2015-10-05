#include <cstdio>
#include <cstring>

using namespace std;

int par[100005];

int find (int v) {
    if (par[v] == -1) return v;
    return par[v] = find(par[v]);
}

void join (int a, int b) {
    if (find(a) != find(b))
        par[find(a)] = find(b);
}

int main () {
    int n, k;
    memset(par, -1, sizeof par);
    scanf(" %d %d", &n, &k);
    for (int i = 0; i < k; i++) {
        char o; int b1, b2;
        scanf(" %c %d %d", &o, &b1, &b2);
        if (o == 'F')
            join(b1, b2);
        else {
            if (find(b1) == find(b2))
                printf("S\n");
            else printf("N\n");
        }
    }
}
