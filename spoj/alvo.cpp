#include <cstdio>

#define MAX_C 1000000

long long r[MAX_C];

int points(int start, int end, long long x, long long y) {
    int c = (start + end)/2;
    if (start == end) return start;
    if (r[c] < (x*x)+(y*y)) points(c+1, end, x, y);
    else points(start, c, x, y);
}

int main() {
    int c, t;
    long long p = 0, x, y;
    
    scanf("%d %d", &c, &t);
    for (int i = 0; i < c; i++) {
        scanf("%lld", &r[i]);
        r[i] *= r[i];
    }
    for (int j = 0; j < t; j++) {
        scanf("%lld %lld", &x, &y);
        if ((x*x)+(y*y) <= r[c-1])
            p += c - (points(0, c-1, x, y));
    }
    printf("%lld\n", p);
}