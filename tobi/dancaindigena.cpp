#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

struct indio {
    int i, d;
} indios[1005];

bool init[1000005];

int mod(int n, int m) {
    return (n + m) % m;
}

int main() {
    int n, e;
    scanf(" %d %d", &n, &e);

    for (int i = 0; i < 1000005; i++) init[i] = false;

    for (int i = 0; i < e; i++) {
        int p, d;
        scanf(" %d %d", &p, &d);
        indios[i].i = --p, indios[i].d = d;
        init[p] = true;
    }

    int pufetadas = 1;
    while (true) {
        set<int> p;
        for (int i = 0; i < e; i++) {
            int v = mod(indios[i].i + indios[i].d * pufetadas, n);
            if (init[v]) p.insert(v);
            else break;
        }
        if (p.size() == e) break;
        pufetadas++;
    }
    printf("%d\n", pufetadas);
}
