#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, t = 1;
    int x[1005];
    int y[1005];
    while (scanf(" %d", &n), n != 0) {
        for (int i = 0; i < n; i++)
            scanf(" %d %d", &x[i], &y[i]);
        sort(x, x + n);
        sort(y, y + n);
        printf("Teste %d\n%d %d\n\n", t++, x[n/2], y[n/2]);
    }
}
