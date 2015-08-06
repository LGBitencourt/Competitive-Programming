#include <cstdio>
#include <algorithm>

using namespace std;

struct h {
    int s, e;
};

bool compare(h a, h b) {
    if (a.e != b.e) return a.e < b.e;
    return a.s < b.s;
}

int main() {
    int n, x, y, c, last;
    h hs[10005];
    c = last = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        hs[i].s = x, hs[i].e = y;
    }

    sort(hs, hs + n, compare);

    for (int i = 0; i < n; i++)
        if (hs[i].s >= last) c++, last = hs[i].e;

    printf("%d\n", c);
}
