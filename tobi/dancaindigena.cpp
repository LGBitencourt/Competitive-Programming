#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

struct indio {
    int i, d;
} indios[1005];

bool init[1005];

int mod(int n, int m) {
    return (n + m) % m;
}

int main() {
    int n, e;
    scanf(" %d %d", &n, &e);

    for (int i = 0; i < 1005; i++) init[i] = false;

    for (int i = 0; i < e; i++) {
        scanf(" %d %d", &indios[i].i, &indios[i].d);
        init[indios[i].i] = true;
    }

    int pufetadas = 1;
    while (true) {
        set<int> p;
        for (int i = 0; i < e; i++) {
            int v = mod(indios[i].i + d*pufetadas, e);
        }
        if (p.size() == e) break;
        else pufetadas++;
    }
    printf("%d\n", pufetadas);
}
