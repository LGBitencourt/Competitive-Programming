#include <cstdio>

int main() {
    int ad, bd, cd, as, bs, cs, xmin;
    while(scanf("%d %d %d %d %d %d", &ad, &bd, &cd, &as, &bs, &cs) != EOF) {
        if (as >= ad) {
            printf("sem min\n");
            continue;
        }
        xmin = -(bd-bs)/(2*(ad-as));
        printf("%d\n", xmin);
    }
    return 0;
}
