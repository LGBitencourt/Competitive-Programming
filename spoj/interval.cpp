#include <bits/stdc++.h>
#define MAX 50005
using namespace std;

int bit[MAX], uf[MAX], c[MAX];
struct germano {
    int a, b, c;
} p[MAX];

bool cmp (germano a, germano b) {
    if (a.b != b.b) return a.b < b.b;
    return a.a < b.a;
}

void update (int idx) {
    for (int i = idx; i < MAX; i += i & -i)
        bit[i] += 1;
}

int query (int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i & -i)
        sum += bit[i];
    return sum;
}

int main () {
    int t, n, a, b, ci, ans;
    scanf (" %d", &t);
    while (t--) {
        ans = 0;
        scanf (" %d", &n);
        for (int i = 1; i < MAX; i++)
            uf[i] = i-1, bit[i] = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %d %d %d", &a, &b, &ci);
            a++, b++;
            p[i].a = a, p[i].b = b, p[i].c = ci;
        }
        sort (p, p + n, cmp);
        for (int i = 0; i < n; i++) {
            while (query (p[i].b) - query (p[i].a-1) < p[i].c) {
                update (uf[p[i].b+1]), uf[p[i].b+1] = uf[uf[p[i].b+1]], p[i].c--, ans++;
            }
        }
        printf ("%d\n", ans);
    }
}

