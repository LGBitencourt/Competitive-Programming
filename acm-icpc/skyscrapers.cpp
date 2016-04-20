#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const double eps = 1e-9;
const int inf = INT_MAX;
////////////////0123456789
const int MAX = 1000004;
const int modn = 1000000007;

int t, n, d, s, ns;
int bit[MAX], h[MAX], in[2*MAX], q[MAX];

void update (int idx, int value) {
    for (int i = idx; i < MAX; i += i&-i)
        bit[i] += value;
}

int query (int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= i&-i)
        sum += bit[i];
    return sum;
}

int main () {
    scanf (" %d", &t);
    while (t--) {
        scanf (" %d %d", &n, &d);
        h[0] = in[n+d] = s = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %d", &in[i]);
            if (in[i] != h[s]) h[++s] = in[i];
        }
        h[++s] = 0;
        for (int i = n; i < n + d; i++) {
            scanf (" %d", &in[i]);
            q[i-n] = in[i];
        }
        sort (in, in + n + d + 1);
        ns = unique (in, in + n + d + 1) - in;
        for (int i = 0; i < ns; i++)
            bit[i] = 0;
        for (int i = 1; i < s; i++)
            h[i] = lower_bound (in, in + ns, h[i]) - in;
        for (int i = 0; i < d; i++)
            q[i] = lower_bound (in, in + ns, q[i]) - in;
        for (int i = 1; i < s; i++) {
            if (h[i] > h[i-1] && h[i] > h[i+1])
                update (h[i], -1);
            else if (h[i] < h[i-1] && h[i] < h[i+1])
                update (h[i], 1);
        }
        for (int i = 0; i < d; i++)
            printf ("%d%c", query (q[i]) + 1, i != d-1 ? ' ' : '\n');
    }
}
