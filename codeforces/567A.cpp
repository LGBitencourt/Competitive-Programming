#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <climits>

using namespace std;

int v[100005];
int n, x;

int main() {
    scanf(" %d", &n);

    for (int i = 1; i <= n; i++)
        scanf(" %d", &v[i]);

    for (int i = 1; i <= n; i++) {
        int mi, ma;
        if (i == n) ma = abs(v[i] - v[1]), mi = abs(v[i] - v[i-1]);
        else if (i == 1) mi = abs(v[i] - v[i + 1]), ma = abs(v[i] - v[n]);
        else ma = max(abs(v[i] - v[1]), abs(v[i] - v[n])), mi = min(abs(v[i] - v[i-1]), abs(v[i] - v[i+1]));
        printf("%d %d\n", mi, ma);
    }
}
