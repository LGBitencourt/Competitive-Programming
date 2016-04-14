#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    long long x;
    while (scanf (" %d", &n), n != 0) {
        long long pans = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            scanf (" %lld", &x);
            ans += x;
            pans += abs(ans);
        }
        printf ("%lld\n", pans);
    }
}
