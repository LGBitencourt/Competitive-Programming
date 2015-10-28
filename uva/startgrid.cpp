#include <cstdio>
#include <map>
#include <cstring>

using namespace std;

int bit[150];

int query (int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update (int x) {
    for (int i = x; i <= 100; i += i&-i)
        bit[i] += 1;
}

int main () {
    int n;
    while (scanf(" %d", &n) != EOF) {
        map<int, int> m;
        int grid[150];
        int inv = 0;
        memset(bit, 0, sizeof bit);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf (" %d", &x);
            m[x] = i;
        }
        for (int i = 0; i < n; i++) {
            int x;
            scanf (" %d", &x);
            grid[i] = m[x];
        }
        for (int i = 0; i < n; i++) {
            inv += i - query(grid[i]);
            update(grid[i]);
        }
        printf ("%d\n", inv);

    }
}
