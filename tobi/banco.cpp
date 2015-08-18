#include <cstdio>
#include <queue>
#include <set>

using namespace std;

int main() {
    int C, N, t, d, w = 0;
    priority_queue<int> caixas;

    scanf("%d %d", &C, &N);
    while (C--) caixas.push(0);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &t, &d);
        int time = caixas.top();
        if (time - t > 20) w++;
        caixas.pop();
        caixas.push(time + d);
    }
    printf("%d\n", w);
}
