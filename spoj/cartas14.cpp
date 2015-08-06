#include <cstdio>

int main() {
    int c[5];
    for (int i = 0; i < 5; i++) scanf(" %d", &c[i]);
    if (c[0] < c[1] && c[1] < c[2] && c[2] < c[3] && c[3] < c[4]) printf("C\n");
    else if (c[0] > c[1] && c[1] > c[2] && c[2] > c[3] && c[3] > c[4]) printf("D\n");
    else printf("N\n");
}
