#include <cstdio>
#include <cstring>

using namespace std;

int bit[10000005];
long long int n, inv;

long long int query(int x) {
    long long int sum = 0;
    for (int i = x; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update(int x) {
    for (int i = x; i <= 10000000; i += i&-i)
        bit[i] += 1;
}

int main () {
    int t;
    scanf(" %d", &t);
    while (t--) {
        inv = 0;
        scanf(" %d", &n);
        memset(bit, 0, sizeof bit);
        for (int i = 0; i < n; i++) {
            int d;
            scanf(" %d", &d);
            inv += i - query(d);
            update(d);
        }
        printf("%lld\n", inv);
    }
}
