#include <bits/stdc++.h>
#define MAX 50005
using namespace std;

int bit[MAX], uf[MAX], a[MAX], b[MAX], c[MAX], p[MAX];

bool cmp (int i, int j) { return b[i] < b[j]; }

void update (int idx) {
    for (int i = idx+1; i < MAX; i += i&-i)
        bit[i] += 1;
}

int query (int idx) {
    int sum = 0;
    for (int i = idx+1; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main () {
    int t, n, ans;
    scanf (" %d", &t);
    while (t--) {
        ans = 0;
        scanf (" %d", &n);
        for (int i = 0; i < MAX; i++)
            uf[i] = i-1, bit[i] = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %d %d %d", &a[i], &b[i], &c[i]);
            p[i] = i;
        }
        sort (p, p + n, cmp);
        for (int i = 0; i < n; i++) {
            int q = c[p[i]] - query(b[p[i]]) + query(a[p[i]]-1);
            while (q > 0){
                update(uf[b[p[i]]+1]);
                uf[b[p[i]]+1] = uf[uf[b[p[i]]+1]];
                q--, ans++;
            }
        }
        printf ("%d\n", ans);
    }
}

