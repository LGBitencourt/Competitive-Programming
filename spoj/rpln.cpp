#include <cstdio>
#include <algorithm>
#include <climits>

#define MAX 1000000

using namespace std;

int tree[MAX];
int input[MAX];

void update(int node, int start, int end, int k, int val) {
    if (start == end) {
        tree[node] = val;
    } else {
        int mid = (start+end)/2;
        if(k <= mid)
            update(2*node, start, mid, k, val);
        else
            update(2*node + 1, mid + 1, end, k, val);
        tree[node] = min(tree[2*node], tree[2*node + 1]);
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || l > end) {
        return INT_MAX;
    } else if (l <= start && r >= end) {
        return tree[node];
    } else {
        int mid = start + (end - start)/2;
        return min(query(node*2, start, mid, l, r), 
            query(node*2 + 1, mid + 1, end, l, r));
    }
}

int main() {
    int t, n, q;
    scanf("%d", &t);
    for (int j = 1; j <= t; j++) {
        printf("Scenario #%d:\n\n", j);
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf(" %d", &x);
            update(1, 1, n, i, x);
        }
        for (int i = 0; i < q; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n\n", query(1, 1, n, l, r));
        }
    }
}
