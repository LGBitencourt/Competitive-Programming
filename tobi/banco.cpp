#include <cstdio>

using namespace std;

int caixas[15];
int C, N, t, d, w = 0;

int m() {
    int c = caixas[0], index = 0;
    for (int i = 1; i < C; i++)
        if (caixas[i] < c) index = i, c = caixas[i];
    return index;
}

int main() {
    scanf("%d %d", &C, &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &t, &d);
        int c = m();
        if (t > caixas[c]) caixas[c] = t;
        if (caixas[c] - t > 20) w++;
        caixas[c] += d; 
    }
    printf("%d\n", w);
}
