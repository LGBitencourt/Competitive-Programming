#include <cstdio>
#include <cmath>

using namespace std;

bool primes[5000005];
int sum[5000005];

void is_deprime(int n) {
}

int main() {
    int a, b;
    for (int i = 0; i < 5000000; i++) primes[i] = true;
    for (int i = 2; i <= 5000000; i++) {
        if (!primes[i]) continue;
        for (int j = 2*i; j <= 5000000; j += i) {
            primes[j] = false;
            sum[j] += i;
        }
    }
    while (scanf(" %d %d", &a, &b), a != 0) {
        int dp = 0;
        while (a <= b) {
            if (primes[sum[a]]){
                dp++;
            }
            a++;
        }
        printf("%d\n", dp);
    }
}
