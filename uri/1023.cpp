#include <cstdio>
#include <math.h>
#include <map>

#define MAX 1000000

using namespace std;

int main() {
    int n, x, y, c = 1, m;
    float totalAverage;
    scanf("%d", &n);
    while(n != 0) {
        m = totalAverage = 0;
        map <int, int> values;
        int i, j;
        for (i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            values[floor(y/x)] += x;
            totalAverage += y;
            m += x;
        }

        printf("Cidade# %d:\n", c);
        c++;
        bool first = true;
        for (map<int, int>::iterator it = values.begin(); it != values.end(); it++) {
            if (first) first = false;
            else putchar(' ');
            printf("%d-%d", it->second, it->first);
        }
        printf("\n");

        printf("Consumo medio: %.2lf m3.\n", trunc((totalAverage/m)*100)/100.0);

        scanf("%d", &n);
        if (n != 0) printf("\n");
    }
    return 0;
}

