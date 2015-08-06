#include <cstdio>

int main() {
    int v, c = 0;
    scanf(" %d", &v);

    if (v > 100) c += 5 * (v - 100) + 167;
    else if (v <= 100 && v > 30) c += 2 * (v - 30) + 27;
    else if (v <= 30 && v > 10) c += (v - 10) + 7;
    else c = 7;

    printf("%d\n", c);
}
