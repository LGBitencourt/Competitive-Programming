#include <cstdio>
#include <stdlib.h>

#define MAX 45000

int bsearch(int arr[], int start, int end, int target) {
    int center = (start + end)/2;
    if (arr[center] == target) return center;
    if (start == end) return -1;
    else {
        if (arr[center] < target) bsearch(arr, center + 1, end, target);
        else bsearch(arr, start, center - 1, target);
    }
}

int main() {
    int n, m, t, c, l = 0;
    int d[MAX];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d[i]);
    }
    for (int j = 0; j < m; j++) {
        int s;
        scanf("%d", &s);
        c = bsearch(d, 0, n, s);
        t += abs(c - l);
        l = c;
    }
    printf("%d\n", t);
}
