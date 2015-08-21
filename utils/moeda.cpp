#include <cstdio>

int n, T;
int v[10005];
int mpd[10005][10005];

int moeda(int i, int t) {
    if (i == n) return 0;
    if (t == 0) return 1;
    if (mpd[i][t] != 0)
        return mpd[i][t];
    int ans = 0;
    if (v[i] <= t)
        ans += moeda(i, t - v[i]);
    ans += moeda(i + 1, t);
    return mpd[i][t] = ans;
}

int main() {
    scanf(" %d %d", &n, &T);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &v[i]);
    }
    printf("%d\n", moeda(0, T));
}
