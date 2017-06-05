#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main () {
    int n;
    vector <ll> p;
    scanf ("%d", &n);
    p.resize (n);
    for (int i = 0; i < n; i++) {
        scanf ("%lld", &p[i]);
    }
    sort (p.begin(), p.end());
    for (int i = 0; i < n - 2; i++) {
        if (p[i] + p[i+1] > p[i+2]) {
            printf ("possible\n");
            return 0;
        }
    }
    printf ("impossible\n");
    return 0;
}
