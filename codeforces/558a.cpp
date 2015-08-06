#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int t, x, a, p, n, maxp, maxn, sumn, sump, sum;
    int positive[100005], negative[100005];

    sumn = sump = p = n = sum = maxp = maxn = 0;

    cin >> t;

    while (t--) {
        cin >> x >> a;
        if (x > 0) {
            positive[p] = a;
            if (x > maxp) maxp = x;
            sump += a;
            p++;
        } else {
            negative[n] = a;
            if (x < maxn) maxn = x;
            sumn += a;
            n++;
        }
        sum += a;
    }

    if (n == p && n - p <= 1 && n - p >= -1) {
        cout << sum << "\n";
    } else if (n > p) {
        sumn = 0;
        for (int i = 0; i <= p; i++) sumn += negative[i];
        cout << sump + sumn << '\n';
    } else {
        sump = 0;
        for (int i = 0; i <= n; i++) sump += positive[i];
        cout << sump + sumn << '\n';
    }
}
