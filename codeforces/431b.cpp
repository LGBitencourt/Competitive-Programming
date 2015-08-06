#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int f[5] = {0, 1, 2, 3, 4};
    int g[5][5];
    int sum, max = 0;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            scanf(" %d", &g[i][j]);
    do {
        sum = g[f[0]][f[1]] + g[f[1]][f[0]] + g[f[2]][f[3]] + g[f[3]][f[2]] +
                  g[f[1]][f[2]] + g[f[2]][f[1]] + g[f[3]][f[4]] + g[f[4]][f[3]] +
                      g[f[2]][f[3]] + g[f[3]][f[2]] + g[f[3]][f[4]] + g[f[4]][f[3]];
        if (sum > max) max = sum;
    } while (next_permutation(f, f+5));
    printf("%d\n", max);
}
