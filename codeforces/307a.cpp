#include <cstdio>
#include <algorithm>

using namespace std;

int ai[2005];
int ia[2005];

int main() {
    int n, a, first = 1;
    scanf(" %d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &a);
        ai[i] = ia[i] = a;
    }

    sort(ia, ia + n);

    for (int i = 0; i < n; i++) {
        if (!first) printf(" ");
        printf("%d", n - (upper_bound(ia, ia + n, ai[i]) - ia) + 1);
        first = 0;
    }
    printf("\n");
}
