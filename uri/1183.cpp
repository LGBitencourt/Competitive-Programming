#include <cstdio>
#include <iostream>

int main() {
    char operation;
    double values[12][12];
    double sum = 0.0;
    int m = 0;

    scanf(" %c", &operation);

    for(int i = 0; i < 12; i++) {
        for(int j = 0; j < 12; j++) {
            double v;
            scanf("%lf", &v);
            if(j > i) {
                sum += v;
                m++;
            }
        }
    }

    if(operation == 'M') sum = sum/m;

    printf("%.1lf\n", sum);

    return 0;
}
