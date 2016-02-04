#include <bits/stdc++.h>
#define debug(args...) fprintf (args...)
#define MAX 400005
#define MIN -99999999
using namespace std;

struct node {
    int size, sum, size_l, sum_l, size_r, sum_r, max_size, max_sum;
    node () {}
    node (int v) {
        size = v;
        sum = size_l = sum_l = size_r = sum_r = max_size = max_sum = 0;
    }
};

node operator + (node a, node b) {
    if (a.size == -1) return b;
    if (b.size == -1) return a;
    node aux;
    aux.size = a.size + b.size;
    aux.sum = a.sum + b.sum;
    aux.sum_l = aux.sum_r = aux.size_l = aux.size_r = aux.max_sum = aux.max_size = MIN;

    if (aux.sum_l < a.sum)
        aux.sum_l = a.sum, aux.size_l = a.size;
    if (aux.sum_l < a.sum_l)
        aux.sum_l = a.sum_l, aux.size_l = a.size_l;
    if (aux.sum_l < a.sum + b.sum_l)
        aux.sum_l = a.sum + b.sum_l, aux.size_l = a.size + b.size_l;
    if (aux.sum_l == a.sum + b.sum_l)
        aux.size_l = max (aux.size_l, a.size + b.size_l);
    if (aux.sum_l == a.sum_l)
        aux.size_l = max (aux.size_l, a.size_l);
    if (aux.sum_l == a.sum)
        aux.size_l = max (aux.size_l, a.size);

    if (aux.sum_r < b.sum)
        aux.sum_r = b.sum, aux.size_r = b.size;
    if (aux.sum_r < b.sum_r)
        aux.sum_r = b.sum_r, aux.size_r = b.size_r;
    if (aux.sum_r < a.sum_r + b.sum)
        aux.sum_r = a.sum_r + b.sum, aux.size_r = a.size_r + b.size;
    if (aux.sum_r == a.sum_r + b.sum)
        aux.size_r = max (aux.size_r, a.size_r + b.size);
    if (aux.sum_r == b.sum_r)
        aux.size_r = max (aux.size_r, b.size_r);
    if (aux.sum_r == b.sum)
        aux.size_r = max (aux.size_r, b.size);

    if (a.max_sum > aux.max_sum)
        aux.max_sum = a.max_sum, aux.max_size = a.max_size;
    else if (a.max_sum == aux.max_sum)
        aux.max_size = max (a.max_size, aux.max_size);
    if (b.max_sum > aux.max_sum)
        aux.max_sum = b.max_sum, aux.max_size = b.max_size;
    else if (b.max_sum == aux.max_sum)
        aux.max_size = max (aux.max_size, b.max_size);
    if (aux.max_sum < a.sum + b.sum_l)
        aux.max_sum = a.sum + b.sum_l, aux.max_size = a.size + b.size_l;
    else if (aux.max_sum == a.sum + b.sum_l)
        aux.max_size = max (aux.max_size, a.size + b.size_l);
    if (aux.max_sum < a.sum_r + b.sum_l)
        aux.max_sum = a.sum_r + b.sum_l, aux.max_size = a.size_r + b.size_l;
    else if (aux.max_sum == a.sum_r + b.sum_l)
        aux.max_size = max (aux.max_size, a.size_r + b.size_l);
    if (aux.max_sum < aux.sum)
        aux.max_sum = aux.sum, aux.max_size = aux.size;
    else if (aux.max_sum == aux.sum)
        aux.max_size = max (aux.max_size, aux.size);
    return aux;
}

node seg[MAX];

void update (int l, int r, int i, int v, int n) {
    if (i < l || i > r) return;
    if (l == r) {
        node aux;
        aux.size = aux.size_l = aux.size_r = aux.max_size = 1;
        aux.sum = aux.sum_l = aux.sum_r = aux.max_sum = v;
        seg[n] = aux;
        return;
    }
    update (l, (l+r)/2, i, v, 2*n);
    update (((l+r)/2)+1, r, i, v, 2*n+1);
    seg[n] = seg[2*n] + seg[2*n+1];
}

node query (int l, int r, int x, int y, int n) {
    if (l > y || r < x) return node (-1);
    if (l >= x && r <= y) return seg[n];
    node a1, a2;
    a1 = query (l, (l+r)/2, x, y, 2*n);
    a2 = query (((l+r)/2)+1, r, x, y, 2*n+1);
    if (a1.size == -1) return a2;
    if (a2.size == -1) return a1;
    return a1 + a2;
}

int main () {
    int t, n, v, q, x, y;
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d", &n);
        for (int i = 0; i < n; i++) {
            scanf (" %d", &v);
            update (0, n-1, i, v, 1);
        }
        scanf (" %d", &q);
        while (q--) {
            scanf (" %d %d", &x, &y);
            node ans = query (0, n-1, x-1, y-1, 1);
            printf ("%d %d\n", ans.max_sum, ans.max_size);
        }
    }
}

