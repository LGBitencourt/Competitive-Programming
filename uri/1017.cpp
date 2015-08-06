
#include <cstdio>

int main() {
    int time, km;
    scanf("%d %d", &time, &km);
    printf("%.3lf\n", (double) km*time/12);
    return 0;
}
