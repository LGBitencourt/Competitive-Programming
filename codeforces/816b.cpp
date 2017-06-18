#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 212345;

int bit[MAXN];

void update(int idx, int val) {
    for (int i = idx; i < MAXN; i += i&-i)
        bit[i] += val;
}

int query(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main() {
    int n, k, q;
    scanf(" %d %d %d", &n, &k, &q);
    for (int i = 0; i < n; i++) {
        int l, r;
        scanf(" %d %d", &l, &r);
        update(l, 1);
        update(r + 1, -1);
    }
    vector<int> r;
    for (int i = 1; i <= 200000; i++)
        if (query(i) >= k) r.push_back(i);
    while (q--) {
        int l, h;
        scanf(" %d %d", &l, &h);
        printf("%d\n", upper_bound(r.begin(), r.end(), h) - lower_bound(r.begin(), r.end(), l));
    }
}

