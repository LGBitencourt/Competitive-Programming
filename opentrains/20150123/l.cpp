#include <bits/stdc++.h>
using namespace std;

int bit[2000011];
int n, inv;

int query(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

void update(int x) {
    for (int i = x; i <= 2000010; i += i&-i)
        bit[i] += 1;
}

int main () {
    int t;
    inv = 0;
    scanf(" %d", &n);
    memset(bit, 0, sizeof bit);

    for (int i = 0; i < n; i++) {
        int d;
        scanf(" %d", &d);
        d += 1000005;
        inv += i - query(d);
        update(d+1);
    }
    printf("%d\n", inv);
}
