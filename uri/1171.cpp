#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    int values[200000];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        values[i] = m;
    }

    std::sort(values, values + n);

    for(j = 0; j < n; j++) {
        int cont = 1;
        int x = values[j];
        values[j] = 0;
        for(i = 0; i < n; i++) {
            if(values[i] == x && values[i] != 0) {
                cont++;
                values[i] = 0;
            }
        }
        if(x != 0) printf("%d aparece %d vez(es)\n", x, cont);
    }

    return 0;
}
