#include <cstdio>
#include <algorithm>
#include <climits>
#include <set>

using namespace std;

int n;
int mpd[70][32100];
int V[100], C[100], U[100][3], P[100];

int pd (int i, int v) {
    if (i > n) return 0;
    if (mpd[i][v]) return mpd[i][v];

    int r1, r2, r3, r4, r5, r6, r7, r8;
    r2 = r3 = r4 = r5 = r6 = r7 = r8 = INT_MIN;

    r1 = pd(i + 1, v);
    if (V[i] <= v && !P[i])
        r2 = V[i]*C[i] + pd(i + 1, v - V[i]);
    
    if (P[i] > 0) {
        if (P[i] >= 1 && V[i] + V[U[i][0]] <= v)
            r3 = V[i]*C[i] + V[U[i][0]]*C[U[i][0]] + pd(i + 1, v - V[i]);
        if (P[i] >= 1 && V[i] + V[U[i][1]] <= v)
            r4 = V[i]*C[i] + V[U[i][1]]*C[U[i][1]] + pd(i + 1, v - V[i]);
        if (P[i] >= 1 && V[i] + V[U[i][2]] <= v)
            r5 = V[i]*C[i] + V[U[i][2]]*C[U[i][2]] + pd(i + 1, v - V[i]);
        if (P[i] >= 2 && V[i] + V[U[i][0]] + V[U[i][1]] <= v)
            r6 = V[i]*C[i] + V[U[i][0]]*C[U[i][0]] + V[U[i][1]]*C[U[i][1]] + pd(i + 1, v - V[i]);
        if (P[i] >= 2 && V[i] + V[U[i][0]] + V[U[i][2]] <= v)
            r7 = V[i]*C[i] + V[U[i][0]]*C[U[i][0]] + V[U[i][2]]*C[U[i][2]] + pd(i + 1, v - V[i]);
        if (P[i] >= 2 && V[i] + V[U[i][0]] + V[U[i][1]] + V[U[i][2]] <= v)
            r8 = V[i]*C[i] + V[U[i][0]]*C[U[i][0]] + V[U[i][2]]*C[U[i][2]] + V[U[i][1]]*C[U[i][1]] + pd(i + 1, v - V[i]);
    }

    mpd[i][v] = max(r1, max(r2, max(r3, max(r4, max(r5, max(r6, max(r7, r8)))))));
    return mpd[i][v];
}

int main() {
    int t, v, c;
    scanf(" %d", &t);
    while (t--) {
        scanf("%d %d", &v, &n);
        for (int i = 0; i < 70; i++) 
           for (int j = 0; j < 32100; j++) mpd[i][j] = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d %d %d", &V[i], &C[i], &c);
            U[c][P[c]++] = i;
        }

        printf("%d\n", pd(1, v));
    }
}
