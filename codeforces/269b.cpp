#include <cstdio>
#include <algorithm>

using namespace std;

int n, m;
int t[5005], pd[5005];

int main() {

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        double trash;
        scanf("%d %lf", t+i, &trash);
    }

    for (int i = 1; i <= n; i++) {
        int j = t[i];
        for (int x = j; x >= 1; x--) {
            pd[j] = max(pd[j], 1 + pd[x]);
        }
    }

    int l = 0;
    for (int i = 1; i <= n; i++) {
        l = max(l, pd[i]);
    }
    printf("%d\n", n-l);
}
