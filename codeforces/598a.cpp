#include <bits/stdc++.h>

using namespace std;

int pot[31];

int main () {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long p;
        for (p = 0; p <= n; p++)
            if ((1 << p) > n) break;
        cout << ((1 + n)*n/2) - 2*((1 << p) - 1) << endl;
    }
}
