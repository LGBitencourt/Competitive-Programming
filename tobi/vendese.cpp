#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, k, step;
    int p[100005];

    scanf("%d %d", &n, &k);
    step = n - k;
    for (int i = 0; i < n; i++) scanf(" %d", &p[i]);
    sort(p, p + n);

    int md;
    for (int i = 0; i < step - 1; i++) md += p[i+1] - p[i];

    for (int i = step; i < n; i++) {
        int diff = md - (p[i - step + 1] - p[i - step]) + (p[i] - p[i - 1]);
        if (diff < md) md = diff;
    }

    printf("%d\n", md);

}
