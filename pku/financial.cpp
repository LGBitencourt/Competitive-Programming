#include <cstdio>

int main() {
    double avg = 0, m;
    for (int i = 0; i < 12; i++) {
        scanf("%lf", &m);
        avg += m;
    }
    printf("$%.2lf\n", avg/12);
}
