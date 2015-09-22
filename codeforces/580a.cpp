#include <bits/stdc++.h>

using namespace std;

int main () {
    ios::sync_with_stdio(false);
    int n, f, c = 1, t = 1;
    cin >> n >> f;
    for (int i = 1; i < n; i++) {
        int k;
        cin >> k;
        if (k >= f) t++;
        else t = 1;
        if (t > c) c = t;
        f = k;
    }
    cout << c << '\n';
}
