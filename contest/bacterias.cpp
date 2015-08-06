#include <cstdio>
#include <math.h>
#define MAX 10000
using namespace std;
int main(){
    int n, a, b, p;
    double log_1, log_2;
    while(scanf("%d", &n) != EOF) {
        p = 1;
        scanf("%d %d", &a, &b);
        log_1 = (b-1)*log(a);

        for(int i = 2; i <= n; i++) {
            scanf("%d %d", &a, &b);
            log_2 = (b-1)*log(a);

            if (log_2 > log_1) {
                log_1 = log_2;
                p = i;
            }
        }

        printf("%d\n", p);
    }
}
