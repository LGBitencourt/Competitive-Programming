#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int MAXN = 112345;
const int modn = 1000000007;

int min_p[MAXN], max_p[MAXN], mic, mac;

ll fexp(ll n, int e) {
    if (e == 0) return 1;
    if (e == 1) return n % modn;
    if (e % 2) return n * fexp(n * n % modn, e / 2) % modn;
    return fexp(n * n % modn, e / 2) % modn;
}

int main() {
    int mi, ma, n, t;
    ll subseq, substr;
    scanf(" %d", &t);
    while (t--) {
        scanf(" %d", &n);
        mi = inf, ma = -inf, mic = mac = 0;
        substr = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf(" %d", &x);
            if (x < mi) {
                mic = 1;
                mi = x;
                min_p[0] = i;
            } else if (x == mi) min_p[mic++] = i;
            if (x > ma) {
                mac = 1;
                ma = x;
                max_p[0] = i;
            } else if (x == ma) max_p[mac++] = i;
        }

        subseq = (mi == ma) ? (fexp(2, n) - 1) % modn : 
            (((fexp(2, mic) - 1) * (fexp(2, mac) - 1) % modn) * (fexp(2, n - mic - mac))) % modn;

        int m = min(min_p[mic - 1], max_p[mac - 1]);
        int a, b, j;
        a = b = j = 0;
        for (int i = 0; i <= m; i++) {
            while (min_p[a] < i) a++;
            while (max_p[b] < i) b++;
            j = max(min_p[a], max_p[b]);
            substr = (substr + n - j) % modn;
        }

        printf("%lld %lld\n", substr, subseq);
    }
}

